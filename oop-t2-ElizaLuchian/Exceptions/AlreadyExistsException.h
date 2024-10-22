//
// Created by 40745 on 24/04/2024.
//

#ifndef OOP_T2_ELIZALUCHIAN_ALREADYEXISTSEXCEPTION_H
#define OOP_T2_ELIZALUCHIAN_ALREADYEXISTSEXCEPTION_H


#include <exception>

class AlreadyExistsException: public std::exception {
const char * what() const noexcept override;
};


#endif //OOP_T2_ELIZALUCHIAN_ALREADYEXISTSEXCEPTION_H
