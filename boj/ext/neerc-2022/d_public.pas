{ SOLUTION for "Decoding Task" problem for NEERC'2002 }
{ (C) Roman Elizarov }

{$A+,B-,D+,E+,F-,G-,I+,L+,N+,O-,P-,Q+,R+,S+,T-,V+,X+,Y+}
program DECODE_SOLUTION;

const
  MAX_N = 10000;

type
  line = array[1..MAX_N + 1] of byte;

function hexchar2byte(c: char): byte;
begin
  case c of
    '0'..'9': hexchar2byte := ord(c) - ord('0');
    'A'..'Z': hexchar2byte := ord(c) - ord('A') + 10;
  end;
end;

function byte2hexchar(b: byte): char;
begin
  case b of
    0..9: byte2hexchar := chr(ord('0') + b);
    10..15: byte2hexchar := chr(ord('A') + b - 10);
  end;
end;

procedure readLine(var l: line; var len: integer); 
var
  c1, c2: char;
begin
  len := 0;
  while not eoln do begin
    read(c1, c2);
    inc(len);
    l[len] := hexchar2byte(c1) shl 4 + hexchar2byte(c2);
  end;
  readln;
end;

procedure writeLine(var l: line; len: integer);
var
  i: integer;
begin
  for i := 1 to len do begin
    write(byte2hexchar(l[i] shr 4));
    write(byte2hexchar(l[i] and 15));
  end;
  writeln;
end;

var
  l1, l2, k: line;
  len1, len2, i: integer;
  c: byte;

begin
  assign(input, 'decode.in'); reset(input);
  assign(output, 'decode.out'); rewrite(output);
  { Read }
  readLine(l1, len1);
  readLine(l2, len2);
  { Solve }
  c := ord(' ');
  for i := 1 to len2 do begin
    k[i] := l2[i] xor c;
    if i < len2 then
      c := k[i] xor l1[i];
  end;
  { Write }
  writeLine(k, len2);
end.
