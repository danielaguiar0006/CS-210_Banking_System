#pragma once

#include <iostream>  // For std::cout, std::cin, std::endl
#include <iomanip>   // For std::setprecision and std::fixed
#include "CalculationEngine.h"

class BankingSystem {
public:
   /**
    * Constructor for the BankingSystem class.
    * Initializes all member variables to 0.
    */
   BankingSystem();

   /**
    * Displays the report of the banking system.
    * This function prints out the initial investment amount, monthly deposit,
    * annual interest percentage, number of years, and prompts the user to press
    * any key to continue.
    */
   void DisplayReport();

   /**
    * Prompts the user to enter various inputs related to a banking system.
    * The function validates the user input and keeps prompting until valid input is entered.
    *
    * Inputs:
    * - m_initialInvestment: The initial investment amount.
    * - m_monthlyDeposit: The monthly deposit amount.
    * - m_annualInterestPercentage: The annual interest percentage.
    * - m_numYears: The number of years.
    */
   void GetUserInput();

   /**
    * Displays static reports for the banking system.
    * The function calculates and displays the year-end balance and interest for each year,
    * both with and without additional monthly deposits.
    */
   void DisplayStaticReports();

   /**
    * Prompts the user if they would like to recalculate and performs the necessary
    * actions based on their choice.
    * If the user chooses 'y' or 'Y', it calls the GetUserInput, DisplayReport,
    * DisplayStaticReports, and PromptForRecalculation functions recursively.
    * If the user chooses 'n' or 'N', it displays "Goodbye!" and exits.
    * If the user enters an invalid choice, it displays an error message and prompts
    * for recalculation again.
    */
   void PromptForRecalculation();
private:
   float m_initialInvestment;
   float m_monthlyDeposit;
   int m_annualInterestPercentage;
   int m_numYears;

   /**
    * Checks if the input is a valid positive integer.
    *
    * @param t_input The t_input value to be checked.
    * @return True if the t_input is a valid positive integer, false otherwise.
    */
   bool checkValidInput(int t_input);


   /**
    * Checks if the input is a valid positive float.
    *
    * @param t_input The t_input value to be checked.
    * @return True if the t_input is a valid positive float, false otherwise.
    */
   bool checkValidInput(float t_input);
};
