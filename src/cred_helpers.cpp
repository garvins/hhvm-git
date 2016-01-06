/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#include "hphp/runtime/ext/extension.h"

#include "hphp/system/systemlib.h"


#include "../ext_git2.h"
#include "cred_helpers.h"

using namespace HPHP;

Resource HHVM_FUNCTION(git_cred_userpass,
	const String& url,
	const String& user_from_url,
	int64_t allowed_types,
	const Variant& payload)
{
    Git2Resource *return_value = new Git2Resource();

	git_cred **cred;
	void *payload_ = NULL;

    git_cred_userpass(cred, url.c_str(), user_from_url.c_str(), (unsigned int) allowed_types, payload_);
    HHVM_GIT2_V(return_value, cred) = *cred;
    return Resource(return_value);
}

