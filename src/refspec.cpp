/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#include "refspec.h"

using namespace HPHP;

String HHVM_FUNCTION(git_refspec_src,
	const Resource& refspec)
{
	const char *result;
	String return_value;

	auto refspec_ = dyn_cast<Git2Resource>(refspec);

	result = git_refspec_src(HHVM_GIT2_V(refspec_, refspec));
	return_value = String(result);
	return return_value;
}

String HHVM_FUNCTION(git_refspec_dst,
	const Resource& refspec)
{
	const char *result;
	String return_value;

	auto refspec_ = dyn_cast<Git2Resource>(refspec);

	result = git_refspec_dst(HHVM_GIT2_V(refspec_, refspec));
	return_value = String(result);
	return return_value;
}

String HHVM_FUNCTION(git_refspec_string,
	const Resource& refspec)
{
	const char *result;
	String return_value;

	auto refspec_ = dyn_cast<Git2Resource>(refspec);

	result = git_refspec_string(HHVM_GIT2_V(refspec_, refspec));
	return_value = String(result);
	return return_value;
}

int64_t HHVM_FUNCTION(git_refspec_force,
	const Resource& refspec)
{
	int result;
	int64_t return_value;

	auto refspec_ = dyn_cast<Git2Resource>(refspec);

	result = git_refspec_force(HHVM_GIT2_V(refspec_, refspec));

	if (result != GIT_OK) {
		SystemLib::throwInvalidArgumentExceptionObject(giterr_last()->message);
	}

	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_refspec_direction,
	const Resource& spec)
{
	git_direction result;
	int64_t return_value;

	auto spec_ = dyn_cast<Git2Resource>(spec);

	result = git_refspec_direction(HHVM_GIT2_V(spec_, refspec));
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_refspec_src_matches,
	const Resource& refspec,
	const String& refname)
{
	int result;
	int64_t return_value;

	auto refspec_ = dyn_cast<Git2Resource>(refspec);

	result = git_refspec_src_matches(HHVM_GIT2_V(refspec_, refspec), refname.c_str());

    if (result != GIT_OK && result != 1) {
		SystemLib::throwInvalidArgumentExceptionObject(giterr_last()->message);
	}

	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_refspec_dst_matches,
	const Resource& refspec,
	const String& refname)
{
	int result;
	int64_t return_value;

	auto refspec_ = dyn_cast<Git2Resource>(refspec);

	result = git_refspec_dst_matches(HHVM_GIT2_V(refspec_, refspec), refname.c_str());

    if (result != GIT_OK && result != 1) {
		SystemLib::throwInvalidArgumentExceptionObject(giterr_last()->message);
	}

	return_value = (int64_t) result;
	return return_value;
}

String HHVM_FUNCTION(git_refspec_transform,
	int64_t outlen,
	const Resource& spec,
	const String& name)
{
	int result;
	String return_value;

	char out;

	auto spec_ = dyn_cast<Git2Resource>(spec);

	result = git_refspec_transform(&out, (size_t) outlen, HHVM_GIT2_V(spec_, refspec), name.c_str());

	if (result != GIT_OK) {
		SystemLib::throwInvalidArgumentExceptionObject(giterr_last()->message);
	}

	return_value = String(&out);
	return return_value;
}

String HHVM_FUNCTION(git_refspec_rtransform,
	int64_t outlen,
	const Resource& spec,
	const String& name)
{
	int result;
	String return_value;

	char out;

	auto spec_ = dyn_cast<Git2Resource>(spec);

	result = git_refspec_rtransform(&out, (size_t) outlen, HHVM_GIT2_V(spec_, refspec), name.c_str());

	if (result != GIT_OK) {
		SystemLib::throwInvalidArgumentExceptionObject(giterr_last()->message);
	}

	return_value = String(&out);
	return return_value;
}

