/* -*- c++ -*- ----------------------------------------------------------
   LAMMPS - Large-scale Atomic/Molecular Massively Parallel Simulator
   https://www.lammps.org/, Sandia National Laboratories
   Steve Plimpton, sjplimp@sandia.gov

   Copyright (2003) Sandia Corporation.  Under the terms of Contract
   DE-AC04-94AL85000 with Sandia Corporation, the U.S. Government retains
   certain rights in this software.  This software is distributed under
   the GNU General Public License.

   See the README file in the top-level LAMMPS directory.
------------------------------------------------------------------------- */

#ifdef PAIR_CLASS
// clang-format off
PairStyle(coul/cut/soft2,PairCoulCutSoft2);
// clang-format on
#else

#ifndef LMP_PAIR_COUL_CUT_SOFT2_H
#define LMP_PAIR_COUL_CUT_SOFT2_H

#include "pair.h"

namespace LAMMPS_NS{

    class PairCoulCutSoft2 : public Pair {
    public:
        PairCoulCutSoft2(class LAMMPS *);

        virtual ~PairCoulCutSoft2();

        virtual void compute(int, int);

        virtual void settings(int, char **);

        void coeff(int, char **);

        void init_style();

        double init_one(int, int);

        void write_restart(FILE *);

        void read_restart(FILE *);

        virtual void write_restart_settings(FILE *);

        virtual void read_restart_settings(FILE *);

        void write_data(FILE *);

        void write_data_all(FILE *);

        virtual double single(int, int, int, int, double, double, double, double &);

        virtual void *extract(const char *, int &);

    protected:
        double cut_global;
        double alpha_global;
        double **cut;
        double **scale;
        double **alpha;

        void allocate();
    };

} // namespace LAMMPS_NS

#endif
#endif