
//The following is a generateRandomKey() function that you may use in Project 1
//Note: you will likely need to #include <random> and #include <ctime>


//generates an uppercase MASC key by shuffling the English alphabet
std::string generateRandomKey()
{
	std::string randomKey{ "ABCDEFGHIJKLMNOPQRSTUVWXYZ" };
	std::random_device rnd;
	const auto seed = rnd.entropy() ? rnd() : time(nullptr);
	std::mt19937_64 eng(static_cast<std::mt19937_64::result_type>(seed));

	std::cout << "\nGenerating random key..." << std::endl;
	shuffle(randomKey.begin(), randomKey.end(), eng);

	return randomKey;	
}