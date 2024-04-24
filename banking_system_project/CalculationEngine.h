#pragma once

class CalculationEngine {
public:
   /**
    * Calculates the year-end balance based on the initial investment, monthly deposit,
    * annual interest rate, and total number of years.
    *
    * @param m_initialInvestment The initial investment amount.
    * @param m_monthlyDeposit The monthly deposit amount.
    * @param m_annualInterestPercentage The annual interest rate as a percentage.
    * @param m_totalYears The total number of years.
    * @return The year-end balance after the specified number of years.
    */
   static float CalculateYearEndBalance(float m_initialInvestment, float m_monthlyDeposit,
      float m_annualInterestPercentage, int m_totalYears);

   /**
    * Calculates the year-end interest for a given year.
    *
    * @param m_initialInvestment The initial investment amount.
    * @param m_monthlyDeposit The monthly deposit amount.
    * @param m_annualInterestPercentage The annual interest rate as a percentage.
    * @param m_currentYear The current year.
    * @return The year-end interest.
    */
   static float CalculateYearEndInterest(float m_initialInvestment, float m_monthlyDeposit,
      float m_annualInterestPercentage, int m_currentYear);
private:
   static const int MONTHS_IN_YEAR = 12;
};
