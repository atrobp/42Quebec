/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 21:37:00 by atopalli          #+#    #+#             */
/*   Updated: 2023/02/09 22:41:20 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

//tester go boomm
int main() {
	ifstream file;
	file.open("../minishell");
	if (file){
		cout << "minishell is compiled!" << endl;
		for (string line; getline(cin, line);) {
			cout << "You entered: " << line << endl;
		}
	}
	else {
		cout << "Make sure to compile minishelt first!" << endl;
	}
	return 0;
}
