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
    Array return_value;
    const git_error *result;
    
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
	const Resource& cpy)
{
	int result;
	int64_t return_value;

	auto cpy_ = dyn_cast<Git2Resource>(cpy);

	result = giterr_detach(HHVM_GIT2_V(cpy_, error));

	if (result != GIT_OK) {
		SystemLib::throwInvalidArgumentExceptionObject(giterr_last()->message);
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

