/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#include "hphp/runtime/base/array-init.h"

#include "errors.h"

using namespace HPHP;

Array HHVM_FUNCTION(giterr_last)
{
	const git_error *result;
	Array return_value;

	result = giterr_last();

	if (result == NULL) {
		return_value = make_map_array("0", "", "1" , 0);
	} else {
		return_value = make_map_array("0", result->message, "1" , result->klass);
	}

	return return_value;
}

void HHVM_FUNCTION(giterr_clear)
{

	giterr_clear();
}

int64_t HHVM_FUNCTION(giterr_detach,
	const Array& cpy)
{
	int result;
	int64_t return_value;

	result = giterr_detach(NULL);

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	return_value = (int64_t) result;
	return return_value;
}

void HHVM_FUNCTION(giterr_set_str,
	int64_t error_class,
	const String& string)
{

	giterr_set_str((int) error_class, string.c_str());
}

void HHVM_FUNCTION(giterr_set_oom)
{

	giterr_set_oom();
}

