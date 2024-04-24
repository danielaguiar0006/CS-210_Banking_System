#include "BankingSystem.h"


BankingSystem::BankingSystem() {
   // Initialize all member variables to 0
   m_initialInvestment = 0;
   m_monthlyDeposit = 0;
   m_annualInterestPercentage = 0;
   m_numYears = 0;
}

void BankingSystem::DisplayReport() {
   // Display the report
   std::cout << "\n********************************************************\n";
   std::cout << "********************** Data Input **********************\n";
   std::cout << "Initial Investment Amount: $" << m_initialInvestment << "\n";
   std::cout << "Monthly Deposit: $" << m_monthlyDeposit << "\n";
   std::cout << "Annual Interest Percentage: %" << m_annualInterestPercentage << "\n";
   std::cout << "Number of years: " << m_numYears << "\n";
   std::cout << "Press any key to continue..." << std::endl;

   // Pause the console
   std::cin.ignore();
   std::cin.get();
}

void BankingSystem::GetUserInput() {
   // Get user input, validate it, and keep prompting until valid input is entered
   do {
      std::cout << "Enter the initial investment amount: $";
      std::cin >> m_initialInvestment;
   } while (!checkValidInput(m_initialInvestment));
   do {
      std::cout << "Enter the monthly deposit amount: $";
      std::cin >> m_monthlyDeposit;
   } while (!checkValidInput(m_monthlyDeposit));
   do {
      std::cout << "Enter the annual interest percentage: %";
      std::cin >> m_annualInterestPercentage;
   } while (!checkValidInput(m_annualInterestPercentage));
   do {
      std::cout << "Enter the number of years: ";
      std::cin >> m_numYears;
   } while (!checkValidInput(m_numYears));
}

void BankingSystem::DisplayStaticReports() {
   float yearEndBalance{};
   float yearEndInterest{};

   // Set precision to 2 decimal places for all floating point numbers
   std::cout << std::fixed << std::setprecision(2);

   // First display report without monthly deposits
   std::cout << "Balance and Interest Without Additional Monthly Deposits\n";
   std::cout << "========================================================\n";
   std::cout << std::left << std::setw(14) << "Year" << std::setw(25) << "Year End Balance" << std::setw(18) << "Year End Interest\n";
   std::cout << "--------------------------------------------------------\n";
   // Calculate and display year-end balance and interest for each year
   for (int year = 1; year <= m_numYears; ++year) {
      yearEndBalance = CalculationEngine::CalculateYearEndBalance(m_initialInvestment, 0, m_annualInterestPercentage, year);
      yearEndInterest = CalculationEngine::CalculateYearEndInterest(m_initialInvestment, 0, m_annualInterestPercentage, year);
      std::cout << std::left << std::setw(14) << year << "$" << std::setw(24) << yearEndBalance << "$" << yearEndInterest << std::endl;
   }

   // Next display report with monthly deposits
   std::cout << "\nBalance and Interest With Additional Monthly Deposits\n";
   std::cout << "========================================================\n";
   std::cout << std::left << std::setw(14) << "Year" << std::setw(25) << "Year End Balance" << std::setw(18) << "Year End Interest\n";
   std::cout << "--------------------------------------------------------\n";
   // Calculate and display the year-end balance and interest for each year
   for (int year = 1; year <= m_numYears; ++year) {
      yearEndBalance = CalculationEngine::CalculateYearEndBalance(m_initialInvestment, m_monthlyDeposit, m_annualInterestPercentage, year);
      yearEndInterest = CalculationEngine::CalculateYearEndInterest(m_initialInvestment, m_monthlyDeposit, m_annualInterestPercentage, year);
      std::cout << std::left << std::setw(14) << year << "$" << std::setw(24) << yearEndBalance << "$" << yearEndInterest << std::endl;
   }
}

void BankingSystem::PromptForRecalculation() {
   char userChoice{};
   std::cout << "Would you like to recalculate? (y/n): ";
   std::cin >> userChoice;
   if (userChoice == 'y' || userChoice == 'Y') {
      GetUserInput();
      DisplayReport();
      DisplayStaticReports();
      PromptForRecalculation();
   }
   else if (userChoice == 'n' || userChoice == 'N') {
      std::cout << "Goodbye!" << std::endl;
   }
   else {
      std::cout << "Invalid choice. Please enter 'y' or 'n'." << std::endl;
      PromptForRecalculation();
   }
}

// --- Helper functions to validate user input ---
bool BankingSystem::checkValidInput(int t_input) {
   // Reset the input stream if the user enters a non-integer value
   if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(9999999, '\n');  // Ignore up to 9999999 characters
      std::cout << "Invalid input. Please enter a positive integer." << std::endl;
      return false;
   }
   else if (t_input < 0) { // Check if the input is a positive integer
      std::cout << "Invalid input. Please enter a positive integer." << std::endl;
      return false;
   }
   // Input passed all checks (Input is a positive integer)
   return true;
}

// Overloaded function to check for positive float input
bool BankingSystem::checkValidInput(float t_input) {
   // Reset the input stream if the user enters a non-float value
   if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(9999999, '\n');  // Ignore up to 9999999 characters
      std::cout << "Invalid input. Please enter a positive float." << std::endl;
      return false;
   }

   else if (t_input < 0.0f) { // Check if the input is a positive float
      std::cout << "Invalid input. Please enter a positive float." << std::endl;
      return false;
   }
   // Input passed all checks (Input is a positive float)
   return true;
}
