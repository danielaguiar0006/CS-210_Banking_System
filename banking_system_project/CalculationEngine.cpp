#include "CalculationEngine.h"


float CalculationEngine::CalculateYearEndBalance(float m_initialInvestment, float m_monthlyDeposit,
   float m_annualInterestPercentage, int m_totalYears) {
   // Initialize the year-end balance to the initial investment
   float yearEndBalance = m_initialInvestment;
   // Calculate the monthly interest rate
   float monthlyInterestRate = m_annualInterestPercentage / 100 / MONTHS_IN_YEAR;
   // Loop through each month for the specified number of years
   for (int i = 0; i < m_totalYears * MONTHS_IN_YEAR; ++i) {
      yearEndBalance += m_monthlyDeposit;                       // Add the monthly deposit
      yearEndBalance += yearEndBalance * monthlyInterestRate; // Add the monthly interest
   }
   // Return the final year-end balance
   return yearEndBalance;
}

float CalculationEngine::CalculateYearEndInterest(float m_initialInvestment, float m_monthlyDeposit,
   float m_annualInterestPercentage, int m_currentYear) {
   // Calculate the year-end balance for the previous year
   float previousYearEndBalance = CalculateYearEndBalance(m_initialInvestment, m_monthlyDeposit, m_annualInterestPercentage, m_currentYear - 1);
   // Calculate the year-end balance for the current year
   float currentYearEndBalance = CalculateYearEndBalance(m_initialInvestment, m_monthlyDeposit, m_annualInterestPercentage, m_currentYear);
   // Calculate the year-end interest by subtracting the previous year's balance
   // and the total deposits for the current year from the current year's balance.
   return currentYearEndBalance - previousYearEndBalance - m_monthlyDeposit * MONTHS_IN_YEAR;
}
