/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User_utils.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:32:30 by nguiard           #+#    #+#             */
/*   Updated: 2023/01/24 14:42:12 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc.hpp"

/**
 * @brief	Finds the ID of the User with the FD
 * 
 * @details Since we have a map of type <ID, User>,
 * 			having a function that return the ID when we
 * 			only have the FD can be really helpfull to
 * 			find the needed User.
 * 
 * @example	users.at(fd_to_id(fd)) -> the User related to
 * 			the fd.
 * 
 * @param fd 		The FD to search the User
 * @return	 		The matching ID of the FD
 */
int	fd_to_id(int fd) {
	user_map::const_iterator	it = g_users.begin();
	user_map::const_iterator	ite = g_users.end();

	for (; it != ite; it++) {
		User *current_user((*it).second);

		if (current_user->get_fd() == fd) {
			return current_user->get_id();
		}
	}
	return -1;
}


// a changer
/**
 * @brief	Finds the User of the associated FD
 * 
 * @details Since we have a map of type <ID, User>,
 * 			having a function that return the User when we
 * 			only have the FD can be really helpfull.
 * 
 * @param fd 		The FD to search the User
 * @return	 		The matching User of the FD
 */
User	*fd_to_user(int fd) {
	user_map::const_iterator	it = g_users.begin();
	user_map::const_iterator	ite = g_users.end();

	for (; it != ite; it++) {
		User *current_user((*it).second);

		if (current_user->get_fd() == fd) {
			return current_user;
		}
	}
	throw invalid_argument("No user matching this fd");
	return NULL;
}

int		nick_to_id(string nick) {
	user_map::const_iterator	it = g_users.begin();
	user_map::const_iterator	ite = g_users.end();

	for (; it != ite; it++) {
		User *current_user((*it).second);

		if (current_user->get_nick() == nick) {
			return current_user->get_id();
		}
	}
	return -1;
}

//	renvoie une string pour avoir un numero de code avec les
//	zeros avant
string	my_itoa(int nb) {
	if (nb > 99)
		return patch::to_string(nb);
	else if (nb > 9)
		return string("0").append(patch::to_string(nb));
	return string("00").append(patch::to_string(nb));
}