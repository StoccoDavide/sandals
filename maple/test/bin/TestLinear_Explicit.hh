/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
 * Copyright (c) 2025, Davide Stocco and Enrico Bertolazzi.                                      *
 *                                                                                               *
 * The Sandals project is distributed under the BSD 2-Clause License.                            *
 *                                                                                               *
 * Davide Stocco                                                               Enrico Bertolazzi *
 * University of Trento                                                     University of Trento *
 * e-mail: davide.stocco@unitn.it                             e-mail: enrico.bertolazzi@unitn.it *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

// C++ generated code for explicit system: Test
// This file has been automatically generated by Sandals.
// DISCLAIMER: If you need to edit it, do it wisely!

#ifndef SANDALS_MAPLE_CODEGEN_TEST_EXPLICIT_SYSTEM_HH
#define SANDALS_MAPLE_CODEGEN_TEST_EXPLICIT_SYSTEM_HH

using namespace Sandals;
using namespace std;

// Test class.
class Test : public Explicit<2, 0>
{
  // Class data
  Real m_l{1.0}; // Pendulum length (m)
  Real m_g{9.81}; // Gravity acceleration (m/s^2)

public:
  using VectorF  = typename Explicit<2, 0>::VectorF;
  using MatrixJF = typename Explicit<2, 0>::MatrixJF;
  using VectorH  = typename Explicit<2, 0>::VectorH;
  using MatrixJH = typename Explicit<2, 0>::MatrixJH;

  // Class constructor.
  Test() : Explicit<2, 0>("Test") {}

  // Pendulum length (m) getter.
  Real get_l() const {return this->m_l;}

  // Pendulum length (m) setter.
  void set_l(Real t_l) {this->m_l = t_l;}

  // Gravity acceleration (m/s^2) getter.
  Real get_g() const {return this->m_g;}

  // Gravity acceleration (m/s^2) setter.
  void set_g(Real t_g) {this->m_g = t_g;}

  // Evaluate the function f.
  VectorF f(VectorF const & in_0, Real in_1) const override
  {
    // Create data' aliases
    Real const & l = this->m_l; // Pendulum length (m)
    Real const & g = this->m_g; // Gravity acceleration (m/s^2)

    // Create inputs' aliases
    Real const & omega = in_0(0); // State variable 1
    Real const & theta = in_0(1); // State variable 2
    Real const & t = in_1; // Independent variable (or time)

    // Evaluate computation sequence
    // Nothing to evaluate

    // Evaluate function entries
    Real t3 = userfun1(t);
    Real out_0 = -t3 * theta * g / l;
    Real out_1 = omega;

    // Return results
    VectorF out_f;
    out_f <<
      out_0, out_1;
    return out_f;
  }

  // Evaluate the Jacobian of f with respect to x.
  MatrixJF Jf_x(VectorF const & /*in_0*/, Real /*in_1*/) const override
  {
    // Create data' aliases
    // None

    // Create inputs' aliases
    // None

    // Evaluate computation sequence
    // Nothing to evaluate

    // Evaluate function entries
    // Nothing to evaluate

    // Return results
    MatrixJF out_Jf_x;
    out_Jf_x.setZero();
    return out_Jf_x;
  }

  // Calculate the vector h of the invariants.
  VectorH h(VectorF const & /*in_0*/, Real /*in_1*/) const override
  {
    // Create data' aliases
    // None

    // Create inputs' aliases
    // None

    // Evaluate computation sequence
    // Nothing to evaluate

    // Evaluate function entries
    // Nothing to evaluate

    // Return results
    VectorH out_h;
    out_h.setZero();
    return out_h;
  }

  // Calculate the Jacobian of h with respect to x.
  MatrixJH Jh_x(VectorF const & /*in_0*/, Real /*in_1*/) const override
  {
    // Create data' aliases
    // None

    // Create inputs' aliases
    // None

    // Evaluate computation sequence
    // Nothing to evaluate

    // Evaluate function entries
    // Nothing to evaluate

    // Return results
    MatrixJH out_Jh_x;
    out_Jh_x.setZero();
    return out_Jh_x;
  }

  // Check if the system is in the defined domain.
  bool in_domain(VectorF const & in_0, Real /*in_1*/) const
  {
    // Create data' aliases
    // None

    // Create inputs' aliases
    Real const & omega = in_0(0); // State variable 1

    // Evaluate computation sequence
    // Nothing to evaluate

    // Evaluate function entries
    Real out_0 = omega;
    Real out_1 = omega;
    Real out_2 = -omega + 1;

    // Return results
    return (out_0 == 0.0) && (out_1 < 0.0) && (out_2 <= 0.0);
  }

  // Evaluate the user function userfun1.
  Real userfun1(Real /*in_0*/) const
  {
    // Create data' aliases
    // None

    // Create inputs' aliases
    // None

    // Evaluate computation sequence
    // Nothing to evaluate

    // Evaluate function entries
    Real out_0 = y;

    // Return results
    return out_0;
  }

  // Evaluate the user function userfun2.
  Real userfun2(Real in_0, Real in_1) const;

  // No specified integration time

  // Evaluate the initial conditions.
  VectorF ics() const
  {
    // Create data' aliases
    // None

    // Create inputs' aliases
    // None

    // Evaluate computation sequence
    // Nothing to evaluate

    // Evaluate function entries
    // Nothing to evaluate

    // Return results
    VectorF out_ics;
    out_ics.setZero();
    return out_ics;
  }

}; // class Test

#endif // SANDALS_MAPLE_CODEGEN_TEST_EXPLICIT_SYSTEM_HH
