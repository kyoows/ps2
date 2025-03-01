{ SOLUTION for "Evacuation Plan" problem for NEERC'2002 }
{ (C) Roman Elizarov, 2002 }

{$A+,B-,D+,E+,F-,G-,I+,L+,N+,O-,P-,Q+,R+,S+,T-,V+,X+,Y+}
{$M 65520,0,655360}
program EVACUATE_SOLUTION;

const
  MAX_N = 100;
  MAX_M = 100;
  MAX_COORD_ABS = 1000;
  MAX_CAPACITY = 1000;

  INF_COST = MAXLONGINT;

type
  TTrPlan = array[1..MAX_M, 1..MAX_M] of integer;
  PTrPlan = ^TTrPlan;

var
  { Input data }
  n, m: integer;
  x, y, b: array[1..MAX_N] of integer;
  p, q, c: array[1..MAX_M] of integer;
  e: array[1..MAX_N, 1..MAX_M] of integer;
  { Working variables }
  i, j, k, l, t: integer;
  ub: array[1..MAX_N] of longint;
  uc: array[1..MAX_M] of longint;
  trcost: array[1..MAX_M, 1..MAX_M] of longint;
  cost: longint;
  tr_from, tr_to: integer;
  found: boolean;
  trplan: PTrPlan;
  optimal: boolean;
  size: integer;

function dist(i, j: integer): integer;
begin
  dist := abs(x[i] - p[j]) + abs(y[i] - q[j]) + 1;
end;

function transfer(j, k: integer; var best_i: integer): longint;
var
  best: longint;
  cost, i: integer;
begin
  best := INF_COST;
  for i := 1 to n do 
    if e[i, j] > 0 then begin
      cost := dist(i, k) - dist(i, j);
      if cost < best then begin
        best := cost;
        best_i := i;
      end;
    end;
  transfer := best;
end;

function trvalid(j, k: integer): boolean;
begin
  trvalid := (j = k) or ((uc[j] > 0) and (uc[k] < c[k]));
end;

function min(x, y: integer): integer;
begin
  if x < y then
    min := x 
  else
    min := y;
end;

procedure maketransfer(j, k: integer);
var
  l, i: integer;
begin
  l := trplan^[j, k];
  if l = 0 then begin
    transfer(j, k, i);
    dec(e[i, j]);
    inc(e[i, k]);
  end else begin
    maketransfer(j, l);
    maketransfer(l, k);
  end;
end;

begin
  { Allocate memory }
  new(trplan);
  { Open input/output }
  assign(input, 'evacuate.in'); reset(input);
  assign(output, 'evacuate.out'); rewrite(output);
  { Read }
  read(n, m);
  for i := 1 to n do 
    read(x[i], y[i], b[i]);
  for j := 1 to m do
    read(p[j], q[j], c[j]);
  for i := 1 to n do
    for j := 1 to m do 
      read(e[i, j]);
  { Solve }
  { Compute usages and determine validity }
  for i := 1 to n do
    ub[i] := 0;
  for j := 1 to m do
    uc[j] := 0;
  for i := 1 to n do
    for j := 1 to m do begin
      inc(ub[i], e[i, j]);
      inc(uc[j], e[i, j]);
    end;
  { Compute intial transfer cost matrix, init transfer plan }
  found := false; { neg transfer }
  for j := 1 to m do begin
    for k := 1 to m do begin 
      trplan^[j, k] := 0;
      trcost[j, k] := transfer(j, k, i);
      if (trcost[j, k] < 0) and trvalid(j, k) then begin
        found := true;
        tr_from := j;
        tr_to := k;
        break;
      end;
    end;
    if found then 
      break;
  end;
  { Use Floyd's and quit as soon as neg cost is found }
  if not found then 
    for l := 1 to m do begin
      for j := 1 to m do
        if trcost[j, l] <> INF_COST then begin
          for k := 1 to m do 
            if trcost[l, k] <> INF_COST then begin
              cost := trcost[j, l] + trcost[l, k];
              if cost < trcost[j, k] then begin
                trcost[j, k] := cost;
                trplan^[j, k] := l;
                if (cost < 0) and trvalid(j, k) then begin
                  found := true;
                  tr_from := j;
                  tr_to := k;
                  break;
                end;
              end;
            end;
          if found then 
            break;
        end;
      if found then
        break;
    end;
  { Floyd's over, now check for loops (need we?) }
  if not found then
    for j := 1 to m do begin
      for k := 1 to m do 
        if (trcost[j, k] <> INF_COST) and (trcost[k, j] <> INF_COST) then begin
          cost := trcost[j, k] + trcost[k, j];
          if cost < trcost[j, j] then begin
            trcost[j, j] := cost;
            trplan^[j, j] := k;
            if cost < 0 then begin
              found := true;
              tr_from := j;
              tr_to := j;
              break;
            end;
          end;
        end;
        if found then
          break;
      end;
  { Now we know!!! }
  optimal := not found;
  if found then begin
    { Let's sent new cost we shall have an adjust plan }
    maketransfer(tr_from, tr_to);
  end;
  { Write }
  if optimal then
    writeln('OPTIMAL')
  else
    writeln('SUBOPTIMAL');
  if not optimal then begin
    for i := 1 to n do begin
      for j := 1 to m do begin
        if j > 1 then
          write(' ');
        write(e[i, j]);
      end;
      writeln;
    end;
  end;
end.
