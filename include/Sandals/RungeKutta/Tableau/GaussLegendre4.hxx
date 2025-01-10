/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
 * Copyright (c) 2025, Davide Stocco and Enrico Bertolazzi.                  *
 *                                                                           *
 * The Sandals project is distributed under the GNU GPLv3.                   *
 *                                                                           *
 * Davide Stocco                                           Enrico Bertolazzi *
 * University of Trento                                 University of Trento *
 * e-mail: davide.stocco@unitn.it         e-mail: enrico.bertolazzi@unitn.it *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#pragma once

#ifndef SANDALS_GAUSSLEGENDRE4_HXX
#define SANDALS_GAUSSLEGENDRE4_HXX

namespace Sandals
{
  // Symplectic Runge-Kutta Methods of High Order Based on W-Transformation, Kaifeng Xia, Yuhao Cong
  // and Geng Sun. Journal of Applied Analysis ans Computation, Volume 7, Number 3, 2017(8), 1185-1199
  // http://www.jaac-online.com/data/article/jaac/preview/pdf/20170325.pdf

  //! \brief Butcher Tableau for the Gauss-Legendre order 4 method.
  //!
  //! Butcher tableau for the Gauss-Legendre order 4 method:
  //!
  //! \f[
  //! \begin{array}{c|cc}
  //!   1/2-t &   1/4 & 1/4-t \\
  //!   1/2+t & 1/4+t &   1/4 \\
  //!   \hline
  //!         &   1/2 &   1/2
  //! \end{array} \text{,}
  //! \f]
  //!
  //! with \f$ t = \frac{\sqrt{3}}{6}\f$.
  class GaussLegendre4Tableau : public Tableau<2>
  {
    public:
    using Tableau<2>::Type;   //!< Runge-Kutta type enumeration.
    using Tableau<2>::Vector; //!< Templetized vector type.
    using Tableau<2>::Matrix; //!< Templetized matrix type.

    //! Class constructor for the Gauss-Legendre order 4 method.
    GaussLegendre4Tableau() {
      this->name  = "GaussLegendre4";
      this->type  = Type::IRK;
      this->order = 4;
      Real t{std::sqrt(3.0)/6.0};
      this->A << 1.0/4.0,   1.0/4.0-t,
                 1.0/4.0+t, 1.0/4.0;
      this->b << 1.0/2.0,   1.0/2.0;
      this->c << 1.0/2.0-t, 1.0/2.0+t;
    }
  }; // class GaussLegendre4Tableau

  //! Class container for the Gauss-Legendre order 4 method.
  template <Size N>
  class GaussLegendre4 : public RungeKutta<2, N>
  {
  public:
    using System = typename Implicit<N>::Pointer; //!< System type.

    //! Class constructor for a Runge-Kutta solver given a Tableau reference.
    //!
    GaussLegendre4() : RungeKutta<2, N>(GaussLegendre4Tableau()) {}

    //! Class constructor for a Runge-Kutta solver given a Tableau reference.
    //! \param[in] t_system The system reference.
    GaussLegendre4(System t_system) : RungeKutta<2, N>(GaussLegendre4Tableau(), t_system) {}

  }; // class GaussLegendre4

} // namespace Sandals

#endif // SANDALS_GAUSSLEGENDRE4_HXX
