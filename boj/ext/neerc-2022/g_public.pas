{ SOLUTION for "Ghost Busters" problem for NEERC'2002 }
{ (C) Roman Elizarov, 2002 }

{$A+,B-,D+,E+,F-,G-,I+,L+,N+,O-,P-,Q+,R+,S+,T-,V+,X+,Y+}
program GHOSTS_SOLUTION;

type
  real = extended;

const 
  MAX_N = 100;
  MAX_COORD = 10000;
  EPS = 1e-10;

type
  TSolution = record
    cnt: integer;
    g: array[1..MAX_N] of integer;
  end;

var
  n, i, j: integer;
  x, y, z, r: array[1..MAX_N] of integer;
  best: TSolution;

{ Returns square length of vector (x,y,z) }
function len2(x, y, z: real): real;
begin
  len2 := x*x + y*y + z*z;
end;

{ Returns length of vector (x,y,z) }
function len(x, y, z: real): real;
begin
  len := sqrt(len2(x, y, z));
end;

{ Returns sqare distance from point (x,y,z) to ray to (0,0,0)=(x0,y0,z0) }
function distray2(x, y, z, x0, y0, z0: real): real;
var
  l2, t2: real;
begin
  l2 := len2(x, y, z); { square of (0,0,0)-(x,y,z) distance }
  t2 := sqr(x*x0 + y*y0 + z*z0) / len2(x0, y0, z0); { square length along the ray }
  distray2 := l2 - t2;
end;

{ Return dot product of vectors }
function dot(x1, y1, z1, x2, y2, z2: real): real;
begin
  dot := x1*x2 + y1*y2 + z1*z2;
end;

{ Compute vector product of vectors }
procedure vec(x1, y1, z1, x2, y2, z2: real; var x3, y3, z3: real);
begin
  x3 := y1*z2 - y2*z1;
  y3 := x2*z1 - x1*z2;
  z3 := x1*y2 - x2*y1;
end;

{ Tries to fire ray into the specified point.
  Updates best solution is needed }
procedure fire(x0, y0, z0: real);
var
  sol: TSolution;
  i : integer;
begin
  { Count all ghosts that intersect this ray }
  sol.cnt := 0;
  for i := 1 to n do 
    if distray2(x[i], y[i], z[i], x0, y0, z0) / r[i] / r[i] < 1 + EPS then begin
      inc(sol.cnt);
      sol.g[sol.cnt] := i;
    end;
  if sol.cnt > best.cnt then 
    best := sol;
end;

{ Tries to fire ray into intersection of cones for ith and jth ghosts }
procedure fireIntersection(i, j: integer);
var
  l_i, l_j, mi, mj: real;
  sin_i, sin_j, sin_ij, sin2_i, sin2_j, sin2_ij: real;
  cos_i, cos_j, cos_ij, cos2_i, cos2_j, cos2_ij: real;
  xc, yc, zc, lc, lc2, adjc: real;
  xn, yn, zn, ln, ln2, adjn: real;
begin
  { Initiale length to centers }
  l_i := len(x[i], y[i], z[i]);
  l_j := len(x[j], y[j], z[j]);
  { Compute angle between centers of the ghosts }
  cos_ij := dot(x[i], y[i], z[i], x[j], y[j], z[j]) / (l_i * l_j);
  cos2_ij := sqr(cos_ij);
  { If vectors are colinear, then exit - not iteresting }
  if cos_ij > 1 - EPS then
    exit;
  sin2_ij := 1 - cos2_ij;
  sin_ij := sqrt(sin2_ij);
  { Compute info about cones for ith and jgh ghost. Their angles! }
  sin_i := r[i] / l_i;
  sin2_i := sqr(sin_i);
  cos2_i := 1 - sin2_i;
  cos_i := sqrt(cos2_i);

  sin_j := r[j] / l_j;
  sin2_j := sqr(sin_j);
  cos2_j := 1 - sin2_j;
  cos_j := sqrt(cos2_j);

  { We shall find 2 intersection rays to fire: vc +- vn,
    where vc - common vector, vn - normal vector. 
    We find vectors with len(vc +- vn) = 1 }

  { Compute common vector length }
  lc2 := (cos2_i + cos2_j - 2*cos_i*cos_j*cos_ij)/sin2_ij;
  lc := sqrt(lc2);
  { Compute common vector direction }
  mi := (cos_i - cos_j * cos_ij) / l_i;
  mj := (cos_j - cos_i * cos_ij) / l_j;
  xc := mi * x[i] + mj * x[j];
  yc := mi * y[i] + mj * y[j];
  zc := mi * z[i] + mj * z[j];
  { Set common vector to a proper length }
  adjc := lc / len(xc, yc, zc);
  xc := xc * adjc;
  yc := yc * adjc;
  zc := zc * adjc;

  { Compute normal vector length }
  ln2 := 1 - lc2;
  if ln2 < EPS then begin
    { Intersection via one ray or no intersection }
    if ln2 > -EPS then
      { Intersection only via one ray }
      fire(xc, yc, zc);
  end else begin
    { Intersection via 2 rays }
    ln := sqrt(ln2);
    { Compute normal vector direction }
    vec(x[i], y[i], z[i], x[j], y[j], z[j], xn, yn, zn);
    { Set normal vector to a proper length }
    adjn := ln / len(xn, yn, zn);
    xn := xn * adjn;
    yn := yn * adjn;
    zn := zn * adjn;
    { Fire two rays }
    fire(xc + xn, yc + yn, zc + zn);
    fire(xc - xn, yc - yn, zc - zn);
  end;
end;

begin
  assign(input, 'ghosts.in'); reset(input);
  assign(output, 'ghosts.out'); rewrite(output);
  { Read }
  read(n);
  for i := 1 to n do
    read(x[i], y[i], z[i], r[i]);
  { Solve }
  best.cnt := 0;
  { Fire to centers of all ghosts }
  for i := 1 to n do
    fire(x[i], y[i], z[i]);
  { Fire to intersections of all pairs of conuses that we view ghosts in }
  for i := 1 to n - 1 do
    for j := i + 1 to n do
      fireIntersection(i, j);
  { Write }
  writeln(best.cnt);
  for i := 1 to best.cnt do begin
    if i > 1 then
      write(' ');
    write(best.g[i]);
  end;
  if best.cnt > 0 then
    writeln;
end.
