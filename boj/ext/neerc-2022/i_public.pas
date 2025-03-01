{ SOLUTION for "Inlay Cutters" problem for NEERC'2002 }
{ (C) Roman Elizarov, 2002 }

{$A+,B-,D+,E+,F-,G-,I+,L+,N+,O-,P-,Q-,R-,S+,T-,V+,X+,Y+}
{$M 65520,0,655360}
program INLAY_SOLUTION;

const
  MAX_DIM = 50;
  MAX_K = 296;

var
  { Input data }
  m, n, k: integer;
  x1, y1, x2, y2: array[1..MAX_K + 4] of integer;
  { Working variables }
  i, j, t, x, y, tl, tr, tu, td: integer;
  a: array[0..2*MAX_DIM, 0..2*MAX_DIM] of boolean; { intersection points }
  d: array[1..MAX_K + 4] of integer; { DIR_XXX }
  cnt: integer;

const
  DIR_HOR = 1; { (0,y) -> (m,y) }
  DIR_VER = 2; { (x,0) -> (x,n) }
  DIR_DG1 = 3; { (x1,y1) -> (x1+t,y1+t) }
  DIR_DG2 = 4; { (x1,y1) -> (x1+t,y1-t) }

const
  dx: array[1..4] of integer = (1, 0, 1, 1);
  dy: array[1..4] of integer = (0, 1, 1, -1);

function BorderType(x, y: integer): integer; 
var
  b: integer;
begin
  b := 0;
  if (x = 0) and (y >= 0) and (y <= n) then
    inc(b, 1);
  if (y = 0) and (x >= 0) and (x <= m) then
    inc(b, 2);
  if (x = m) and (y >= 0) and (y <= n) then
    inc(b, 4);
  if (y = n) and (x >= 0) and (x <= m) then
    inc(b, 8);
  BorderType := b;
end;

function IsSamePoint(x1, y1, x2, y2: integer): boolean;
begin
  IsSamePoint := (x1 = x2) and (y1 = y2);
end;

procedure Swap(var x, y: integer);
var 
  t: integer;
begin
  t := x;
  x := y;
  y := t;
end;

procedure SwapPoints(var x1, y1, x2, y2: integer);
begin
  Swap(x1, x2);
  Swap(y1, y2);
end;

function GetDirAndOrder(var x1, y1, x2, y2: integer): integer;
begin
    if y1 = y2 then begin
      GetDirAndOrder := DIR_HOR;
      if x1 > x2 then
        SwapPoints(x1, y1, x2, y2);
    end else if x1 = x2 then begin
      GetDirAndOrder := DIR_VER;
      if y1 > y2 then
        SwapPoints(x1, y1, x2, y2);
    end else if x2 - x1 = y2 - y1 then begin
      GetDirAndOrder := DIR_DG1;
      if x1 > x2 then
        SwapPoints(x1, y1, x2, y2);
    end else if x2 - x1 = y1 - y2 then begin
      GetDirAndOrder := DIR_DG2;
      if x1 > x2 then
        SwapPoints(x1, y1, x2, y2);
    end else
      GetDirAndOrder := 0;
end;

function IsOnCut(i, x, y: integer): boolean;
begin
  case d[i] of 
  DIR_HOR: IsOnCut := y = y1[i];
  DIR_VER: IsOnCut := x = x1[i];
  DIR_DG1: IsOnCut := x - x1[i] = y - y1[i];
  DIR_DG2: IsOnCut := x - x1[i] = y1[i] - y;
  end;
end;

procedure MarkIntersection(i, j, x, y: integer);
begin
  if (x >= 0) and (x <= m) and (y >= 0) and (y <= n) then
    a[x, y] := true;
end;

function GetNearest(x, y, dx, dy: integer): integer;
var
  t: integer;
begin
  inc(x, dx);
  inc(y, dy);
  t := 1;
  while (x >= 0) and (x <= m) and (y >= 0) and (y <= n) do begin
    if a[x, y] then begin
      GetNearest := t;
      exit;
    end;
    inc(t);
    inc(x, dx);
    inc(y, dy);
  end;
  GetNearest := -1;
end;

function IsSegment(x1, y1, x2, y2: integer): boolean; 
var
  i, dir, t: integer;
begin
  dir := GetDirAndOrder(x1, y1, x2, y2);
  if dir = 0 then begin
    IsSegment := false;
    exit;
  end;
  for i := 1 to k do 
    if (d[i] = dir) and IsOnCut(i, x1, y1) and IsOnCut(i, x2, y2) then begin
      t := GetNearest(x1, y1, dx[dir], dy[dir]);
      IsSegment := (x1 + t*dx[dir] = x2) and (y1 + t*dy[dir] = y2);
      exit;
    end;
  IsSegment := false;
end;

begin
  assign(input, 'inlay.in'); reset(input);
  assign(output, 'inlay.out'); rewrite(output);
  {=== Read ===}
  read(m, n, k);
  for i := 1 to k do 
    read(x1[i], y1[i], x2[i], y2[i]);
  {=== Solve ===}
  { Multiply everything by 2, so that intersections are integer }
  m := m * 2;
  n := n * 2;
  for i := 1 to k do begin
    x1[i] := x1[i] * 2;
    y1[i] := y1[i] * 2;
    x2[i] := x2[i] * 2;
    y2[i] := y2[i] * 2;
  end;
  { add "cut lines" for plate border }
  inc(k);
  x1[k] := 0;
  y1[k] := 0;
  x2[k] := m;
  y2[k] := 0;
  inc(k);
  x1[k] := m;
  y1[k] := 0;
  x2[k] := m;
  y2[k] := n;
  inc(k);
  x1[k] := m;
  y1[k] := n;
  x2[k] := 0;
  y2[k] := n;
  inc(k);
  x1[k] := 0;
  y1[k] := n;
  x2[k] := 0;
  y2[k] := 0;
  { initialize cut directions, order points of cuts }
  for i := 1 to k do 
    d[i] := GetDirAndOrder(x1[i], y1[i], x2[i], y2[i]);
  { mark intersection points }
  fillchar(a, sizeof(a), false);
  for i := 1 to k do 
    for j := 1 to k do 
      if i <> j then begin
        if (d[i] = DIR_VER) and (d[j] = DIR_HOR) then
          MarkIntersection(i, j, x1[i], y1[j])
        else if (d[i] = DIR_VER) and (d[j] = DIR_DG1) then
          MarkIntersection(i, j, x1[i], y1[j] + x1[i] - x1[j])
        else if (d[i] = DIR_VER) and (d[j] = DIR_DG2) then
          MarkIntersection(i, j, x1[i], y1[j] - x1[i] + x1[j])
        else if (d[i] = DIR_HOR) and (d[j] = DIR_DG1) then
          MarkIntersection(i, j, x1[j] + y1[i] - y1[j], y1[i])
        else if (d[i] = DIR_HOR) and (d[j] = DIR_DG2) then
          MarkIntersection(i, j, x1[j] - y1[i] + y1[j], y1[i])
        else if (d[i] = DIR_DG1) and (d[j] = DIR_DG2) then begin
          t := (x1[j] + y1[j] - x1[i] - y1[i]) div 2;
          MarkIntersection(i, j, x1[i] + t, y1[i] + t);
        end;
      end;
  { Count triangles }
  cnt := 0;
  { 4 potential triangles per every HOR|VER intersection } 
  for i := 1 to k do
    if d[i] = DIR_VER then
      for j := 1 to k do
        if d[j] = DIR_HOR then begin
          x := x1[i];
          y := y1[j];
          { go left, right, up, down to nearest intersection }
          tl := GetNearest(x, y, -1, 0);
          tr := GetNearest(x, y, 1, 0);
          tu := GetNearest(x, y, 0, 1);
          td := GetNearest(x, y, 0, -1);
          if (tl > 0) and (td > 0) and IsSegment(x - tl, y, x, y - td) then
            inc(cnt);
          if (tl > 0) and (tu > 0) and IsSegment(x - tl, y, x, y + tu) then
            inc(cnt);
          if (tr > 0) and (td > 0) and IsSegment(x + tr, y, x, y - td) then
            inc(cnt);
          if (tr > 0) and (tu > 0) and IsSegment(x + tr, y, x, y + tu) then
            inc(cnt);
        end;
  { 4 potential triangles per every DG1|DG2 intersection } 
  for i := 1 to k do
    if d[i] = DIR_DG1 then
      for j := 1 to k do
        if d[j] = DIR_DG2 then begin
          t := (x1[j] + y1[j] - x1[i] - y1[i]) div 2;
          x := x1[i] + t;
          y := y1[i] + t;
          if (x >= 0) and (x <= m) and (y >= 0) and (y <= n) then begin
            { go left (leftdown), right (rightup), up (leftup), down (rightdown) to nearest intersection }
            tl := GetNearest(x, y, -1, -1);
            tr := GetNearest(x, y, 1, 1);
            tu := GetNearest(x, y, -1, 1);
            td := GetNearest(x, y, 1, -1);
            if (tl > 0) and (td > 0) and IsSegment(x - tl, y - tl, x + td, y - td) then
              inc(cnt);
            if (tl > 0) and (tu > 0) and IsSegment(x - tl, y - tl, x - tu, y + tu) then
              inc(cnt);
            if (tr > 0) and (td > 0) and IsSegment(x + tr, y + tr, x + td, y - td) then
              inc(cnt);
            if (tr > 0) and (tu > 0) and IsSegment(x + tr, y + tr, x - tu, y + tu) then
              inc(cnt);
          end;
        end;
  {=== Write ===}
  writeln(cnt);
end.
