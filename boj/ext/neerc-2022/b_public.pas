{ SOLUTION for "Bricks" problem for NEERC'2002 }
{ (C) Roman Elizarov, 2002 }

{ NOTE: Solution very long and complex, because all calculations are
        performed in integer numbers }

{$A+,B-,D+,E+,F-,G-,I+,L+,N+,O-,P-,Q+,R+,S+,T-,V+,X+,Y+}
program BRICKS_SOLUTION;

const
  PRECISION = 10;  
  MIN_LEN = 1 * PRECISION;
  MAX_LEN = 10 * PRECISION;

  BASE = 10000; { for lcmp and lmul }
  BASE2 = BASE * BASE;

function conv(a_: double): integer;
begin
  conv := round(a_ * PRECISION);
end;

function longsqr(l: longint): longint;
begin
  longsqr := l*l;
end;

{ long multiplication of a1 and a2 with result written in 4 digits by BASE }
procedure lmul(a, b: longint; var d0, d1, d2, d3: integer);
var
  a0, a1, b0, b1: longint;
  t: longint;
begin
  a0 := a mod BASE;
  a1 := a div BASE;
  b0 := b mod BASE;
  b1 := b div BASE;

  t := a0 * b0;
  d0 := t mod BASE;
  t := t div BASE + a0 * b1 + a1 * b0;
  d1 := t mod BASE;
  t := t div BASE + a1 * b1;
  d2 := t mod BASE;
  d3 := t div BASE;
end;

function icmp(a, b: integer): integer;
begin
  if a > b then
    icmp := 1
  else if a < b then
    icmp := -1
  else
    icmp := 0;
end;

{ compares a1 * a2 with b1 * b2 }
function lcmp(a1, a2, b1, b2: longint): integer;
var
  res: integer;
var
  p0, p1, p2, p3: integer;
  q0, q1, q2, q3: integer;
begin
  lmul(a1, a2, p0, p1, p2, p3);
  lmul(b1, b2, q0, q1, q2, q3);
  res := icmp(p3, q3);
  if res = 0 then
    res := icmp(p2, q2);
  if res = 0 then
    res := icmp(p1, q1);
  if res = 0 then
    res := icmp(p0, q0);
  lcmp := res;
end;

function fits(a, b, d, e: integer): boolean;
var
  t: integer;
  res: boolean;
  x: longint;
begin
  { Let A <= B }
  if a > b then begin
    t := a;
    a := b;
    b := t;
  end;
  if d < a then begin
    res := false;
    fits := res;
    exit;
  end;
  if d*d >= a*a + b*b then begin
    { Only e here determines fitness }                                 
    res := e >= a;
    fits := res;
    exit;
  end;

  x := 2*longint(a)*b*d - longint(e)*(a*a + b*b);

  { Do we have a valid (non-negative) t in "-" case of it?
    Yes, if D*A >= B*SQ, that is if 
    D^2*A^2 >= B^2*(A^2 + B^2 - D^2)
  }

  if longsqr(d)*longsqr(a) >= longsqr(b)*(a*a + b*b - d*d) then begin
    { "-" case for t is more advanteous, and we just need to check:
        x <= SQ*(B^2 - A^2)
    }

    if x < 0 then begin
      res := true;
      fits := res;
      {$IFDEF VERBOSE}
      writeln(a, 'x', b, ' ', d, 'x', e, ' ', res, ' (d in range, t-, x < 0)',
        ' t-=', (d * longsqr(a) - a*b*sqrt(a*a + b*b - d*d))/(a*a + b*b):0:3,
        ' t+=', (d * longsqr(a) + a*b*sqrt(a*a + b*b - d*d))/(a*a + b*b):0:3);
      {$ENDIF}
      exit;
    end else begin 

      { x >= 0 and

        x^2 <= SQ^2*(B^2 - A^2)^2
        x^2 <= (A^2 + B^2 - D^2)*(B^2 - A^2)^2 
      }

      res := lcmp(x, x, a*a + b*b - d*d, longsqr(b*b - a*a)) <= 0;

      fits := res;
      {$IFDEF VERBOSE}
      writeln(a, 'x', b, ' ', d, 'x', e, ' ', res, ' (d in range, t-, x >= 0)', 
          ' t-=', (d * longsqr(a) - a*b*sqrt(a*a + b*b - d*d))/(a*a + b*b):0:3,
          ' t+=', (d * longsqr(a) + a*b*sqrt(a*a + b*b - d*d))/(a*a + b*b):0:3);
      {$ENDIF}
      exit;
    end;
  end else begin
    { "-" case for t is not valid... so we shall check for "+" case, i.e.
      x <= -SQ*(B^2 - A^2) }

    if x > 0 then begin
      res := false;
      fits := res;
      {$IFDEF VERBOSE}
      writeln(a, 'x', b, ' ', d, 'x', e, ' ', res, ' (d in range, t+, x > 0)', 
        ' t-=', (d * longsqr(a) - a*b*sqrt(a*a + b*b - d*d))/(a*a + b*b):0:3,
        ' t+=', (d * longsqr(a) + a*b*sqrt(a*a + b*b - d*d))/(a*a + b*b):0:3);
      {$ENDIF}
      exit;
    end else begin 

      { x <= 0 and

        x^2 >= SQ^2*(B^2 - A^2)^2
        x^2 >= (A^2 + B^2 - D^2)*(B^2 - A^2)^2 
      }

      res := lcmp(-x, -x, a*a + b*b - d*d, longsqr(b*b - a*a)) >= 0;

      fits := res;
      {$IFDEF VERBOSE}
      writeln(a, 'x', b, ' ', d, 'x', e, ' ', res, ' (d in range, t+, x >= 0)', 
          ' t-=', (d * longsqr(a) - a*b*sqrt(a*a + b*b - d*d))/(a*a + b*b):0:3,
          ' t+=', (d * longsqr(a) + a*b*sqrt(a*a + b*b - d*d))/(a*a + b*b):0:3);
      {$ENDIF}
      exit;
    end;
  end;
end;

var
  a_, b_, c_, d_, e_: double;
  a, b, c, d, e: integer;

begin
  assign(input, 'bricks.in'); reset(input);
  assign(output, 'bricks.out'); rewrite(output);
  { Read }
  readln(a_, b_, c_, d_, e_);
  { Convert into integers }
  a := conv(a_);
  b := conv(b_);
  c := conv(c_);
  d := conv(d_);
  e := conv(e_);
  { Solve & Write }
  if fits(a, b, d, e) or fits(a, b, e, d) or
     fits(a, c, d, e) or fits(a, c, e, d) or
     fits(b, c, d, e) or fits(b, c, e, d) then
    writeln('YES')
  else
    writeln('NO');
end.

