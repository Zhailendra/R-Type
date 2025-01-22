/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** ErrorHandler.hpp
*/

#ifndef RTYPE_ERRORHANDLER_HPP
#define RTYPE_ERRORHANDLER_HPP

#include <iostream>

namespace rtype {
    class ErrorHandler : public std::exception {
        public:
            explicit ErrorHandler(std::string msg) : _msg(std::move(msg)){};

            const char *what() const noexcept override {
                return (_msg.c_str());
            }

        private:
            const std::string _msg;
    };
} // rtype

#endif