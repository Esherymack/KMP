/* Implementation of the Knuth-Morris-Pratt algorithm for string matching
	Author: Madison Tibbett
	Reference: Cormen, et. al., p. 1002 - "Knuth Morris Pratt"
	Date: 05/10/2020

    Copyright (C) 2020  Madison L. Tibbett

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include <iostream>

#include "Matcher.h"
#include "Utility.h"


int main()
{
	std::cout << "begin" << std::endl;

	process();

	return 0;
}