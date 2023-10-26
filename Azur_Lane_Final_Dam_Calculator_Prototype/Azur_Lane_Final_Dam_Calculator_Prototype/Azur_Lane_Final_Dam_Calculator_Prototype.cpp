// Azur_Lane_Final_Dam_Calculator_Prototype.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>

//Program is meant to calculate final damage formula of Azur Lane ship guns, i.e. DD, CL/CA/CB, BB, etc. guns.
//Mathematical formula & information about stats & variables used in this calculator is from: https://azurlane.koumakan/jp/wiki/Combat#Final_Weapon_Damage
//NOTE: The term 'Buff' in games often refers to a bonus added on to a certain statistic or set of statistics in-game, be it for the player character or for NPCs.
//Program was from scratch, current version provides a basic calculation of the final damage statistic using the mathematical formula.

//main function for calculator.
int main()
{
	//Create intiger value for inputting weapon base damage.
	int WPNBaseDMG;
	std::cout << "Enter Weapon's base damage value: ";
	std::cin >> WPNBaseDMG;

	//create float value for inputting coefficient value.
	float WPNCoeff;
	std::cout << "Enter Weapon's coefficient value: ";
	std::cin >> WPNCoeff;

	//create float value for inputting the specific ship's gear slot efficiency value
	float SlotEff;
	std::cout << "Enter Unit's Slot Efficiency: ";
	std::cin >> SlotEff;

	//create int value for specific Unit's raw firepower stat.
	int Firepower;
	std::cout << "Enter Unit's firepower stat: ";
	std::cin >> Firepower;

	//create float value for firepower divided by 100 for equation.
	float FPCalc;
	FPCalc = Firepower / 100;

	//create float value for bonus provided by formation buffs.
	float FormationBonus;
	std::cout << "Enter the Formation Bonus value: ";
	std::cin >> FormationBonus;

	//create float value for bonus provided by skills that buff FP stat.
	float FPSkillBonus;
	std::cout << "Enter Firepower skill bonus value: ";
	std::cin >> FPSkillBonus;

	//create int value for a randomly generated number between 0 and 2
	//
	// NOTE TO SELF: Remake this section into a Random Number Generator once program functions with manual inputs.
	//
	int Random;
	std::cout << "Enter random integer between 0 and 2: ";
	std::cin >> Random;

	//Create float value for armor modifier bonus.
	float ArmorModifier;
	std::cout << "Enter Armor Modifier value: ";
	std::cin >> ArmorModifier;

	//create float value for the level advantage bonus.
	//NOTE: 
	float LevelAdvantageDamageBonus;
	std::cout << "Enter the level advantage bonus value: ";
	std::cin >> LevelAdvantageDamageBonus;

	//create float value for the ammo buff bonus.
	float AmmoBuff;
	std::cout << "Enter the ammo buff value: ";
	std::cin >> AmmoBuff;

	//float value for the damage bonus.
	float DamageBonus;
	std::cout << "Enter the damage bonus value: ";
	std::cin >> DamageBonus;

	//float value for the ammo type modifier bonus.
	//This refers to a skill that buffs ammo modifiers. If no such skill is active, then the value should be 0.
	float AmmoTypeModifier;
	std::cout << "Enter the ammo type modifier value: ";
	std::cin >> AmmoTypeModifier;

	//Float value for the enemy debuff value.
	//this refers to a skill that debuffs the enemy, making them take increased damage. If no such skill is active, the value should be 0.
	float EnemyDebuff;
	std::cout << "Enter the enemy debuff value: ";
	std::cin >> EnemyDebuff;

	//Float value for Hunter skill.
	//This refers to a skill that provides extra damage to a certain enemy. If no skill is active, the value is 0.
	float HunterSkill;
	std::cout << "Enter the Hunter skill bonus value: ";
	std::cin >> HunterSkill;

	//Create int value for the ManualBit variable.
	int ManualBit;
	//ManualBit determines if Manual is active or not in-game. As Manual provides a bonus to a BB's first salvo.
	std::cout << "Enter the Manual Bit Value. Please use 1 if manual is active, 0 if not active for this calculation.";
	std::cin >> ManualBit;

	//create float value for ManualModifier.
	float ManualModifier;
	std::cout << "Enter the Manual Modifier value: ";
	std::cin >> ManualModifier;

	//create int variable for the CriticalBit value. 
	//CriticalBit refers to if a critical hit has procced or not. 1 if yes, 0 if not.
	int CriticalBit;
	std::cout << "Enter the CriticalBit value. Please use 1 if a critical hit would be scored, 0 if not, for this calculation.";
	std::cin >> CriticalBit;

	//float variable for critical modifier value.
	float CriticalModifier;
	std::cout << "Enter the critical modifier value: ";
	std::cin >> CriticalModifier;


	//Variable created to calculate the final damage using the mathematical formula from the wiki.
	float FPSum;
	FPSum = (WPNBaseDMG * WPNCoeff * SlotEff * (1 + FPCalc * (1 + FormationBonus + FPSkillBonus)) + Random) * ArmorModifier * LevelAdvantageDamageBonus * (1 + AmmoBuff + DamageBonus) * (1 + AmmoTypeModifier) * (1 + EnemyDebuff) * (1 + HunterSkill) * (1 + ManualBit * (0.2 + ManualModifier)) * (1 + CriticalBit * (0.5 + CriticalModifier));


	std::cout << "Test Result = " << FPSum;




	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
