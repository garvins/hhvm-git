/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#include "hphp/runtime/ext/extension.h"

#include "hphp/system/systemlib.h"


#include "../ext_git2.h"
#include "message.h"

using namespace HPHP;

String HHVM_FUNCTION(git_message_prettify,
	int64_t out_size,
	const String& message,
	int64_t strip_comments)
{
	String return_value;

	char *out = NULL;

	git_message_prettify(out, (size_t) out_size, message.c_str(), (int) strip_comments);
	return_value = String(out);
	return return_value;
}

