#include <iostream>
#include "tools.h"
#include <stdexcept>

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
  /**
  TODO:
    * Calculate the RMSE here.
  */
	if (estimations.size() == 0 || estimations.size() != ground_truth.size()) {
            throw std::invalid_argument( "CalculateRMSE () - Error: Invalid input values." );
        }

        Eigen::VectorXd rmse(estimations[0].array().size());
        rmse << 0,0,0,0;

        for (int i = 0; i < estimations.size(); ++i) {
            Eigen::VectorXd res = estimations[i] - ground_truth[i];
            res = res.array() * res.array();
            rmse += res;
        }

        rmse /= estimations.size();
        rmse = rmse.array().sqrt();

        return rmse;
}
