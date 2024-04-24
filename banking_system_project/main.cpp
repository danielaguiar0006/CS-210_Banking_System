/*
 * Description: The Airgead Banking App offers a straightforward tool for visualizing
 * projected investment growth through compound interest, based on user-defined input
 * parameters. It efficiently demonstrates the effects of regular contributions and
 * varying interest rates on long-term savings. The approach taken for the code design
 * is object-oriented.
 *
 * Author: Daniel Aguiar
 * Date: 04/04/2024
*/

#include "BankingSystem.h"

/**
 * The main function is the entry point of the program.
 * It creates an instance of the BankingSystem class and performs the following steps:
 * 1. Displays the welcome message and Report Screen with empty data.
 * 2. Gets user input.
 * 3. Displays the report with the user's input.
 * 4. Displays the static reports.
 * 5. Allows the user to test different values.
 *
 * @return 0 indicating successful program execution.
 */
int main() {
   // Create an instance of the BankingSystem class
   BankingSystem bankingSystem;

   // Step 1: Display the welcome message and Report Screen with empty data
   std::cout << "\nWelcome to the Airgead Banking Investment Calculator!\n";
   bankingSystem.DisplayReport();

   // Step 2: Get user input
   bankingSystem.GetUserInput();

   // Step 3: Display the report with the user's input
   bankingSystem.DisplayReport();

   // Step 4: Display the static reports
   bankingSystem.DisplayStaticReports();

   // Step 5: Allow the user to test different values
   bankingSystem.PromptForRecalculation();

   return 0;
}
