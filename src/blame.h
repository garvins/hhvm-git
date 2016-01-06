/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#ifndef HHVM_GIT2_BLAME_H
#define HHVM_GIT2_BLAME_H


using namespace HPHP;

int64_t HHVM_FUNCTION(git_blame_get_hunk_count,
	const Resource& blame);

Resource HHVM_FUNCTION(git_blame_get_hunk_byindex,
	const Resource& blame,
	int64_t index);

Resource HHVM_FUNCTION(git_blame_get_hunk_byline,
	const Resource& blame,
	int64_t lineno);

Resource HHVM_FUNCTION(git_blame_file,
	const Resource& repo,
	const String& path,
	const Resource& options);

Resource HHVM_FUNCTION(git_blame_buffer,
	const Resource& reference,
	const String& buffer,
	int64_t buffer_len);

void HHVM_FUNCTION(git_blame_free,
	const Resource& blame);

#endif

