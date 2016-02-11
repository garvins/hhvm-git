/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#ifndef HHVM_GIT2_SYS_COMMIT_H
#define HHVM_GIT2_SYS_COMMIT_H

#include "../ext_git2.h"

using namespace HPHP;

int64_t HHVM_FUNCTION(git_commit_create_from_oids,
	const String& oid,
	const Resource& repo,
	const String& update_ref,
	const Array& author,
	const Array& committer,
	const String& message_encoding,
	const String& message,
	const String& tree,
	int64_t parent_count,
	const String& parents);

#endif

