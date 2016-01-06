/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#ifndef HHVM_GIT2_SYS_ODB_BACKEND_H
#define HHVM_GIT2_SYS_ODB_BACKEND_H


using namespace HPHP;

void HHVM_FUNCTION(git_odb_backend_malloc,
	const Resource& backend,
	int64_t len);

#endif

