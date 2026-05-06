#include "BacktrackingWLOpt.hh"

void BacktrackingWLOpt::FirstOfLevel()
{
  out.Assign(level, 0);
}

bool BacktrackingWLOpt::NextOfLevel()
{
  int w = out.Assignment(level);
  if (w < (int)in.Warehouses() - 1)
  {
    out.Assign(level, w + 1);
    return true;
  }
  return false;
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
