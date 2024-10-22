//
// Created by 40745 on 24/04/2024.
//

#include "AlreadyExistsException.h"

const char *AlreadyExistsException::what() const noexcept {
    return "this element already exists";
}
