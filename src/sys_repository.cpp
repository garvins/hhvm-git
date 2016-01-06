/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#include "hphp/runtime/ext/extension.h"
#include "hphp/system/systemlib.h"

#include "../ext_git2.h"
#include "sys_repository.h"

using namespace HPHP;

Resource HHVM_FUNCTION(git_repository_new)
{
	Git2Resource *return_value = new Git2Resource();

	git_repository **out = NULL;

	git_repository_new(out);
	HHVM_GIT2_V(return_value, repository) = *out;
	return Resource(return_value);
}

void HHVM_FUNCTION(git_repository__cleanup,
	const Resource& repo)
{

	auto repo_ = dyn_cast<Git2Resource>(repo);

	git_repository__cleanup(HHVM_GIT2_V(repo_, repository));
}

int64_t HHVM_FUNCTION(git_repository_reinit_filesystem,
	const Resource& repo,
	int64_t recurse_submodules)
{
	int result;
	int64_t return_value;

	auto repo_ = dyn_cast<Git2Resource>(repo);

	result = git_repository_reinit_filesystem(HHVM_GIT2_V(repo_, repository), (int) recurse_submodules);
	return_value = (int64_t) result;
	return return_value;
}

void HHVM_FUNCTION(git_repository_set_config,
	const Resource& repo,
	const Resource& config)
{

	auto repo_ = dyn_cast<Git2Resource>(repo);
	auto config_ = dyn_cast<Git2Resource>(config);

	git_repository_set_config(HHVM_GIT2_V(repo_, repository), HHVM_GIT2_V(config_, config));
}

void HHVM_FUNCTION(git_repository_set_odb,
	const Resource& repo,
	const Resource& odb)
{

	auto repo_ = dyn_cast<Git2Resource>(repo);
	auto odb_ = dyn_cast<Git2Resource>(odb);

	git_repository_set_odb(HHVM_GIT2_V(repo_, repository), HHVM_GIT2_V(odb_, odb));
}

void HHVM_FUNCTION(git_repository_set_refdb,
	const Resource& repo,
	const Resource& refdb)
{

	auto repo_ = dyn_cast<Git2Resource>(repo);
	auto refdb_ = dyn_cast<Git2Resource>(refdb);

	git_repository_set_refdb(HHVM_GIT2_V(repo_, repository), HHVM_GIT2_V(refdb_, refdb));
}

void HHVM_FUNCTION(git_repository_set_index,
	const Resource& repo,
	const Resource& index)
{

	auto repo_ = dyn_cast<Git2Resource>(repo);
	auto index_ = dyn_cast<Git2Resource>(index);

	git_repository_set_index(HHVM_GIT2_V(repo_, repository), HHVM_GIT2_V(index_, index));
}

