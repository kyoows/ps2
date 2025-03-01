{ SOLUTION for "Heroes Of Might And Magic" problem for NEERC'2002 }
{ (C) Roman Elizarov, 2002 }

{$A+,B-,D+,E+,F-,G-,I+,L+,N+,O-,P-,Q+,R+,S+,T-,V+,X+,Y+}
{$M 65520,0,655360}
program HEROES_SOLUTION;

const
  MAX_N = 10;
  MAX_HPH = 100;
  MAX_MPH = 50;
  MAX_HPM = 10;
  MAX_NM = 10;
  MAX_L = 10;

  MAX_H = MAX_HPM * MAX_NM;

const
  CAST_LIGHTNING = MAX_N + 1;
  CAST_HEAL = MAX_N + 2;

type
  TArray = array[1..MAX_MPH, 1..MAX_H, 1..MAX_N] of byte;
  PArray = ^TArray;

var
  { Input data }
  n, hph, mph, hpm, nm, v, dh: integer;
  l: array[1..MAX_N] of integer;
  { Working variables }
  best_hph: PArray;
  best_spell: PArray;

function GetHPNeed(cur_mph, cur_h, cur_p: integer): integer;
var
  cur_nm, next_p, next_h, next_hph: integer;
  best, cur, spell: integer;
  i: integer;
begin
  if cur_mph = 0 then begin
    GetHPNeed := hph + 1; { Infinite number of hitpoints is needed }
    exit;
  end;
  if best_hph^[cur_mph, cur_h, cur_p] = 0 then begin
    { Hero's move! }
    cur_nm := (cur_h + hpm - 1) div hpm;
    next_p := cur_p - v;
    if next_p < 1 then
      next_p := 1;
    { Try "Lightning Bolt" }
    next_h := cur_h - l[cur_p];
    spell := CAST_LIGHTNING;
    if next_h <= 0 then begin
      { Killed monsters! So, having at lest 1 hp will be enough! }
      best := 1;
    end else begin
      best := GetHPNeed(cur_mph - 1, next_h, next_p);
      if next_p = 1 then
        inc(best, (next_h + hpm - 1) div hpm); { Need more hp to stay alive if hit this turn }
      if best > hph then
        best := hph + 1; { Trim it... }
    end;
    { Try "Heal" }
    cur := GetHPNeed(cur_mph - 1, cur_h, next_p);
    if cur <= hph then begin
      { It's possible to be alive next turn!! }
      if next_p = 1 then
        inc(cur, cur_nm); { Will need more if hit to stay alive }
      if cur <= hph then begin
        { Still Ok... Then could apply heal }
        dec(cur, dh);
        if cur < 1 then
          cur := 1; { at lest one is always needed }
        if cur < best then begin
          best := cur;
          spell := CAST_HEAL;
        end;
      end;
    end;
    { Try "Teleport" (makes sence to teleport to v + 1 and further) }
    for i := v + 1 to n do begin
      next_p := i - v;
      cur := GetHPNeed(cur_mph - 1, cur_h, next_p);
      if next_p = 1 then
        inc(cur, cur_nm); { Will need more if hit to stay alive }
      if cur < best then begin { Teleport's better!!! }
        best := cur;
        spell := i;
      end;
    end;
    { Record best solution }
    best_hph^[cur_mph, cur_h, cur_p] := best;
    best_spell^[cur_mph, cur_h, cur_p] := spell;
  end;
  GetHPNeed := best_hph^[cur_mph, cur_h, cur_p];
end;

var
  i, spell, hp_need: integer;
  sim_hph, sim_h, sim_p: integer;

begin
  {=== Allocate memory ===}
  new(best_hph);
  new(best_spell);
  {=== Open input/output ===}
  assign(input, 'heroes.in'); reset(input);
  assign(output, 'heroes.out'); rewrite(output);
  {=== Read ===}
  read(n, hph, mph, hpm, nm, v, dh);
  for i := 1 to n do
    read(l[i]);
  {=== Solve ===}
  fillchar(best_hph^, sizeof(best_hph^), 0);
  fillchar(best_spell^, sizeof(best_spell^), 0);
  sim_hph := hph;
  sim_h := hpm * nm;
  sim_p := n;
  hp_need := GetHPNeed(mph, sim_h, sim_p);
  {=== Write ===}
  if hp_need <= hph then begin
    writeln('VICTORIOUS');
    for i := mph downto 1 do begin
      spell := best_spell^[i, sim_h, sim_p];
      { Write & apply spell }
      if spell = CAST_LIGHTNING then begin
        writeln('L');
        dec(sim_h, l[sim_p]);
      end else if spell = CAST_HEAL then begin
        writeln('H');
        inc(sim_hph, dh);
        if sim_hph > hph then
          sim_hph := hph;
      end else begin
        writeln('T ', spell);
        sim_p := spell;
      end;
      { Check mosters death }
      if sim_h <= 0 then
        break;
      { Move monsters }
      dec(sim_p, v);
      if sim_p <= 1 then begin
        sim_p := 1;
        dec(sim_hph, (sim_h + hpm - 1) div hpm);
      end;
    end;
  end else 
    writeln('DEFEATED');
end.
