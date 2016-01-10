/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#include "hphp/system/systemlib.h"

#include "revparse.h"

using namespace HPHP;

Resource HHVM_FUNCTION(git_revparse_single,
	const Resource& repo,
	const String& spec)
{
	auto return_value = req::make<Git2Resource>();

	git_object **out = NULL;

	auto repo_ = dyn_cast<Git2Resource>(repo);

	git_revparse_single(out, HHVM_GIT2_V(repo_, repository), spec.c_str());
	HHVM_GIT2_V(return_value, object) = *out;
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_revparse_ext,
	const Resource& repo,
	const String& spec)
{
	auto return_value = req::make<Git2Resource>();

	git_object **object_out = NULL;
	git_reference **reference_out_;

	auto repo_ = dyn_cast<Git2Resource>(repo);

	git_revparse_ext(object_out, reference_out_, HHVM_GIT2_V(repo_, repository), spec.c_str());
	//HHVM_GIT2_V(return_value, object) = *object_out; todo return array
	return Resource(return_value);
}

int64_t HHVM_FUNCTION(git_revparse,
	const Resource& revspec,
	const Resource& repo,
	const String& spec)
{
	int result;
	int64_t return_value;

	auto revspec_ = dyn_cast<Git2Resource>(revspec);
	auto repo_ = dyn_cast<Git2Resource>(repo);

	result = git_revparse(HHVM_GIT2_V(revspec_, revspec), HHVM_GIT2_V(repo_, repository), spec.c_str());
	return_value = (int64_t) result;
	return return_value;
}

