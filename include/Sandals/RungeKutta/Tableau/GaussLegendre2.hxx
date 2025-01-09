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

#ifndef SANDALS_GAUSSLEGENDRE2_HXX
#define SANDALS_GAUSSLEGENDRE2_HXX

namespace Sandals
{
  // Symplectic Runge-Kutta Methods of High Order Based on W-Transformation, Kaifeng Xia, Yuhao Cong
  // and Geng Sun. Journal of Applied Analysis ans Computation, Volume 7, Number 3, 2017(8), 1185-1199
  // http://www.jaac-online.com/data/article/jaac/preview/pdf/20170325.pdf

  //! Butcher tableau for the Gauss-Legendre 2 method:
  //!
  //! \f[
  //! \begin{array}{c|c}
  //!   1/2 & 1/2 \\
  //!   \hline
  //!       & 1
  //! \end{array} \text{.}
  //! \f]
  class GaussLegendre2Tableau : public Tableau<1>
  {
    public:
    using Tableau<1>::Type;   //!< Runge-Kutta type enumeration.
    using Tableau<1>::Vector; //!< Templetized vector type.
    using Tableau<1>::Matrix; //!< Templetized matrix type.

    //! Class constructor for the Gauss-Legendre 2 method.
    GaussLegendre2Tableau() {
      this->name  = "GaussLegendre2";
      this->type  = Type::IRK;
      this->order = 2;
      this->A << 1.0/2.0;
      this->b << 1.0;
      this->c << 1.0/2.0;
    }
  }; // class GaussLegendre2Tableau

  //! Class container for the Gauss-Legendre 2 method.
  template <Size N>
  class GaussLegendre2 : public RungeKutta<1, N>
  {
  public:
    using System = typename Implicit<N>::Pointer; //!< System type.

    //! Class constructor for a Gauss-Legendre 2 solver given a Tableau reference.
    //! \param[in] t_tableau The Tableau reference.
    GaussLegendre2() : RungeKutta<1, N>(GaussLegendre2Tableau()) {}

    //! Class constructor for a Gauss-Legendre 2 solver given a Tableau reference.
    //! \param[in] t_tableau The Tableau reference.
    //! \param[in] t_system The system reference.
    GaussLegendre2(System t_system) : RungeKutta<1, N>(GaussLegendre2Tableau(), t_system) {}

  }; // class GaussLegendre2

} // namespace Sandals

#endif // SANDALS_GAUSSLEGENDRE2_HXX
