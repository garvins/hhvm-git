/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#include "hphp/runtime/base/array-init.h"

#include "signature.h"

using namespace HPHP;

Array HHVM_FUNCTION(git_signature_new,
	const String& name,
	const String& email,
	int64_t time,
	int64_t offset)
{
	int result;
	Array return_value;

	git_signature *out = NULL;

	result = git_signature_new(&out, name.c_str(), email.c_str(), (git_time_t) time, (int) offset);

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	return_value = null_array;
	return return_value;
}

Array HHVM_FUNCTION(git_signature_now,
	const String& name,
	const String& email)
{
	int result;
	Array return_value;

	git_signature *out = NULL;
	char *name_ = NULL, *email_ = NULL;
	
	result = git_signature_now(&out, name.c_str(), email.c_str());
	
	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}
	
    if (out->name != NULL) {
        name_ = out->name;
    }
    
    if (out->email != NULL) {
        email_ = out->email;
    }
    
    return_value = make_map_array("name" , name_, "email", email_, "time", 0 /* todo return time */);
    
    return return_value;
}

Array HHVM_FUNCTION(git_signature_default,
	const Resource& repo)
{
	int result;
	Array return_value;

	git_signature *out = NULL;

	auto repo_ = dyn_cast<Git2Resource>(repo);

	result = git_signature_default(&out, HHVM_GIT2_V(repo_, repository));

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	return_value = null_array;
	return return_value;
}

Array HHVM_FUNCTION(git_signature_dup,
	const Array& sig)
{
	git_signature *result;
	Array return_value;

	result = git_signature_dup(NULL);
	return_value = null_array;
	return return_value;
}

void HHVM_FUNCTION(git_signature_free,
	const Array& sig)
{

	git_signature_free(NULL);
}

