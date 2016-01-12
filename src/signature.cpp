/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#include "hphp/system/systemlib.h"

#include "hphp/runtime/base/array-init.h"
#include "signature.h"

using namespace HPHP;

Resource HHVM_FUNCTION(git_signature_new,
	const String& name,
	const String& email,
	int64_t time,
	int64_t offset)
{
	auto return_value = req::make<Git2Resource>();

	git_signature *out = NULL;

	git_signature_new(&out, name.c_str(), email.c_str(), (git_time_t) time, (int) offset);
	HHVM_GIT2_V(return_value, signature) = out;
	return Resource(return_value);
}

Array HHVM_FUNCTION(git_signature_now,
	const String& name,
	const String& email)
{
	git_signature *out = NULL;
    char *name_ = NULL, *email_ = NULL;
    Array return_value;
    
    git_signature_now(&out, name.c_str(), email.c_str());
    
    if (out->name != NULL) {
        name_ = out->name;
    }
    
    if (out->email != NULL) {
        email_ = out->email;
    }
    
    return_value = make_map_array("name" , name_, "email", email_, "time", 0 /* todo return time */);
    
    return return_value;
}

Resource HHVM_FUNCTION(git_signature_default,
	const Resource& repo)
{
	auto return_value = req::make<Git2Resource>();

	git_signature *out = NULL;

	auto repo_ = dyn_cast<Git2Resource>(repo);

	git_signature_default(&out, HHVM_GIT2_V(repo_, repository));
	HHVM_GIT2_V(return_value, signature) = out;
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_signature_dup,
	const Resource& sig)
{
	git_signature *result;
	auto return_value = req::make<Git2Resource>();

	auto sig_ = dyn_cast<Git2Resource>(sig);

	result = git_signature_dup(HHVM_GIT2_V(sig_, signature));
	HHVM_GIT2_V(return_value, signature) = result;
	return Resource(return_value);
}

void HHVM_FUNCTION(git_signature_free,
	const Resource& sig)
{

	auto sig_ = dyn_cast<Git2Resource>(sig);

	git_signature_free(HHVM_GIT2_V(sig_, signature));
}

