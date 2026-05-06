#include "BacktrackingWLOpt.hh"

void BacktrackingWLOpt::FirstOfLevel()
{
  out.Assign(level, 0);
}

bool BacktrackingWLOpt::NextOfLevel()
{
  unsigned next_w = (unsigned)(out.Assignment(level) + 1); // cast not necessary, but it makes it clear (return unisgned and not int)
  if (next_w >= in.Warehouses())
  {
    out.Assign(level, -1);
    return false;
  }
  out.Assign(level, (int)next_w);
  return true;
}

bool BacktrackingWLOpt::Feasible()
{
  if (level < 0)
    return true;
  int w = out.Assignment(level);
  return out.Load((unsigned)w) <= in.Capacity((unsigned)w);
}

unsigned BacktrackingWLOpt::Cost()
{
  return out.TotalCost();
}

bool BacktrackingWLOpt::NonImprovingBranch()
{
  return out.TotalCost() >= best_cost;
}
  
void BacktrackingWLOpt::GoUpOneLevel()
{
  out.Assign(level, -1);
  level--;
}
