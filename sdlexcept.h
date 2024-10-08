#pragma once

#include <specdefvals_core.h>
#include <specfuncs_core.h>

_SDL_BEGIN

/*
DEIRROR'S EXCEPTION -> dexception
*/

typedef char char_except[_MAX_ASCII_CODE + _BIN];

typedef class dexception {

public:
	_SDL_FUNC dexception() : _message("Exception") {}

	_SDL_FUNC dexception(const_char_ptr _new_message) {

		if (_new_message) {

			string_copy(_message, _new_message);

		}
	}

	_SDL_FUNC const_char_ptr was() {

		return _message;

	}

protected:
	char_except _message = _EMPTY;

} spec_excp;

class nullptr_dexcept : public dexception {

public:
	_SDL_FUNC nullptr_dexcept() : dexception("Nullptr") {}

	_SDL_FUNC nullptr_dexcept(const_char_ptr _new_message) : dexception(_new_message) {}

};

class empty_dexcept : public dexception {

public:
	_SDL_FUNC empty_dexcept() : dexception("Empty") {}

	_SDL_FUNC empty_dexcept(const_char_ptr _new_message) : dexception(_new_message) {}

};

class invalid_args : public dexception {

public:
	_SDL_FUNC invalid_args() : dexception("Invalid arguments") {}

	_SDL_FUNC invalid_args(const_char_ptr _new_message) : dexception(_new_message) {}

};

class out_of_range : public dexception {

public:
	_SDL_FUNC out_of_range() : dexception("Out of range") {}

	_SDL_FUNC out_of_range(const_char_ptr _new_message) : dexception(_new_message) {}

};

class file_error : public dexception {

public:
	_SDL_FUNC file_error() : dexception("File error") {}

	_SDL_FUNC file_error(const_char_ptr _new_message) : dexception(_new_message) {}

};

//more if needed

#define _THROW_DEXCEPTION(dexcept_type, description) \
throw sdl::dexcept_type(description)

_SDL_END