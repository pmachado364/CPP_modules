/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmachado <pmachado@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:53:15 by pmachado          #+#    #+#             */
/*   Updated: 2025/08/20 17:04:42 by pmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>

std::string get_input(const std::string& prompt);
std::string get_input_nb(const std::string& prompt);
bool is_number(const std::string& s);
void tabs_replace(std::string &s);
int stringToInt(const std::string& s);

#endif