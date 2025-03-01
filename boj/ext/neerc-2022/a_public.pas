{ SOLUTION for "Amusing Numbers" problem for NEERC'2002 }
{ (C) Roman Elizarov, 2002 }

{$A+,B-,D+,E+,F-,G-,I+,L+,N+,O-,P-,Q+,R+,S+,T-,V+,X+,Y+}
{$M 65520,0,655360}
program AMUSING_SOLUTION;

const
  MAX_NUM = 1000000000;
  MAX_DIG = 30;

type
  TDecimal = record
    cnt: integer;
    d: array[-MAX_DIG..MAX_DIG] of integer;
  end;

procedure parse(l: longint; var d: TDecimal); 
var
  i: integer;
begin
  for i := -MAX_DIG to MAX_DIG do
    d.d[i] := 0;
  d.cnt := 0;
  while l > 0 do begin
    d.d[d.cnt] := l mod 10;
    l := l div 10;
    inc(d.cnt);
  end;
end;

procedure add(a, b: TDecimal; var c: TDecimal);
var
  r, i: integer;
begin
  parse(0, c);
  r := 0;
  i := 0;
  while (r <> 0) or (i < a.cnt) or (i < b.cnt) do begin
    r := r + a.d[i] + b.d[i];
    c.d[i] := r mod 10;
    r := r div 10;                                  
    inc(i);
  end;
  c.cnt := i;
end;

procedure sub(a, b: TDecimal; var c: TDecimal);
var
  r, i: integer;
begin
  parse(0, c);
  r := 0;
  i := 0;
  while (r <> 0) or (i < a.cnt) or (i < b.cnt) do begin
    r := r + a.d[i] - b.d[i];
    c.d[i] := (r + 100) mod 10;
    r := (r + 100) div 10 - 10;
    inc(i);
  end;
  c.cnt := i;
end;

function cmp(var a, b: TDecimal): integer;
var
  i, j: integer;
begin
  j := a.cnt;
  if b.cnt > j then
    j := b.cnt;
  for i := j - 1 downto 0 do begin
    if a.d[i] > b.d[i] then begin
      cmp := 1;
      exit;
    end else if a.d[i] < b.d[i] then begin
      cmp := -1;
      exit;
    end;
  end;
  cmp := 0;
end;

procedure println(var d: TDecimal);
var
  i: integer;
begin
  for i := d.cnt - 1 downto 0 do
    write(d.d[i]);
  writeln;
end;

var
  k, m, n: longint;
  kd, md, cd, nd, td, ad: TDecimal;
  i, j: integer;
  found: boolean;

begin
  assign(input, 'amusing.in'); reset(input);
  assign(output, 'amusing.out'); rewrite(output);
  { Read }
  read(k, m);
  { Init p10 }
  parse(k, kd);
  parse(m, md);
  { Solve }
  parse(1, cd); { Will use "cd" as a counter of number less that k in lex order }
  found := false;
  for i := 1 to MAX_DIG do begin
    { t - properly shifted k }
    parse(0, td);
    td.cnt := i;
    for j := 0 to kd.cnt - 1 do
      td.d[j - kd.cnt + td.cnt] := kd.d[j];
    dec(td.d[i - 1]);
    { All i digit numbers smaller t are before k in lex order }
    add(cd, td, ad);
    if i < kd.cnt then begin
      { One more number }
      parse(1, td);
      add(ad, td, ad);
    end;
    if i >= kd.cnt then begin
      { We have enough digits }
      if cmp(cd, md) > 0 then begin
        { Counter is already too large -- no solution }
        found := false;
        break;
      end;
      if cmp(ad, md) >= 0 then begin
        { Solution is here with this number of digits }
        sub(md, cd, nd);
        nd.cnt := i;
        inc(nd.d[i - 1]);
        { Carefully check for k itself }
        if cmp(nd, kd) = 0 then begin
          { just Ok. n = k }
          found := true;
          break;
        end else if cmp(nd, kd) < 0 then begin
          { m is too small }
          { continue with more digits }
        end else begin
          { Ok. Larger than k }
          parse(1, td);
          sub(nd, td, nd);
          found := true;
          break;
        end;
      end;
    end;
    cd := ad;
  end;
  { Write }
  if found then
    println(nd)
  else
    writeln(0);
end.
