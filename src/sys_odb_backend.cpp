/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#include "hphp/system/systemlib.h"

#include "sys_odb_backend.h"

using namespace HPHP;

void HHVM_FUNCTION(git_odb_backend_malloc,
	const Resource& backend,
	int64_t len)
{

	auto backend_ = dyn_cast<Git2Resource>(backend);

	git_odb_backend_malloc(HHVM_GIT2_V(backend_, odb_backend), (size_t) len);
}

