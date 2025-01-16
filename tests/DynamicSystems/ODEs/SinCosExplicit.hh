/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
 * Copyright (c) 2025, Davide Stocco and Enrico Bertolazzi.                  *
 *                                                                           *
 * The Sandals project is distributed under the BSD 2-Clause License.        *
 *                                                                           *
 * Davide Stocco                                           Enrico Bertolazzi *
 * University of Trento                                 University of Trento *
 * e-mail: davide.stocco@unitn.it         e-mail: enrico.bertolazzi@unitn.it *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#pragma once

#ifndef TESTS_SINCOS_EXPLICIT_HH
#define TESTS_SINCOS_EXPLICIT_HH

using namespace Sandals;

class SinCosExplicit : public Explicit<2, 0>
{
public:
  using VectorF  = typename Explicit<2, 0>::VectorF;
  using MatrixJF = typename Explicit<2, 0>::MatrixJF;
  using VectorH  = typename Explicit<2, 0>::VectorH;
  using MatrixJH = typename Explicit<2, 0>::MatrixJH;

  SinCosExplicit() : Explicit<2, 0>("SinCosExplicit") {}

  ~SinCosExplicit() {}

  VectorF f(VectorF const &/*x*/, Real t) const override
  {
    VectorF f;
    f << std::cos(t), std::sin(t);
    return f;
  }

  MatrixJF Jf_x(VectorF const &/*x*/, Real /*t*/) const override
  {return MatrixJF::Zero();}

  VectorH h(VectorF const &/*x*/, Real /*t*/) const override {return VectorH::Zero();}

  MatrixJH Jh_x(VectorF const &/*x*/, Real /*t*/) const override {return MatrixJH::Zero();}

  bool in_domain(VectorF const &/*x*/, Real /*t*/) const override {return true;}

  VectorF ics() const {return VectorF::Zero();}

  VectorF analytical_solution(Real t) const {
    VectorF x;
    x << std::sin(t), Real(1.0)-std::cos(t);
    return x;
  }

  MatrixX analytical_solution(VectorX const &t) const {
    MatrixX x(2, t.size());
    for (int i = 0; i < t.size(); ++i) {x.col(i) = this->analytical_solution(t(i));}
    return x;
  }
};

#endif // TESTS_SINCOS_EXPLICIT_HH
