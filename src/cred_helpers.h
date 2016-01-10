/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#ifndef HHVM_GIT2_CRED_HELPERS_H
#define HHVM_GIT2_CRED_HELPERS_H

#include "../ext_git2.h"

using namespace HPHP;

Resource HHVM_FUNCTION(git_cred_userpass,
    const String& url,
	const String& user_from_url,
	int64_t allowed_types,
	const Variant& payload);

#endif

