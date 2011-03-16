/**
 * \file bio.cpp
 * \author Julien Kauffmann <julien.kauffmann@freelan.org>
 * \brief A bio sample file.
 */

#include <cryptoplus/bio/bio_chain.hpp>
#include <cryptoplus/error/error_strings.hpp>

#include <iostream>
#include <string>

#include <cstdio>

int main()
{
	cryptoplus::error::error_strings_initializer error_strings_initializer;

	std::cout << "BIO sample" << std::endl;
	std::cout << "==========" << std::endl;
	std::cout << std::endl;

	std::cout << "Type some text that should be converted to base64: " << std::flush;
	std::string str;
	std::getline(std::cin, str);

	cryptoplus::bio::bio_chain bio_chain(BIO_f_base64());
	bio_chain.first().push(BIO_new_fd(STDOUT_FILENO, BIO_NOCLOSE));

	std::cout << "Result: " << std::flush;

	bio_chain.first().puts(str);
	bio_chain.first().flush();

	return EXIT_SUCCESS;
}
