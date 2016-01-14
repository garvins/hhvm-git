/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#include "sys_refs.h"

using namespace HPHP;

Resource HHVM_FUNCTION(git_reference__alloc,
	const String& name,
	const String& oid,
	const String& peel)
{
	git_reference *result;
	auto return_value = req::make<Git2Resource>();

	git_oid oid_;
	git_oid peel_;

	if (git_oid_fromstr(oid_, oid.c_str()) != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error->message);
	}
	if (git_oid_fromstr(peel_, peel.c_str()) != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error->message);
	}

	result = git_reference__alloc(name.c_str(), oid_, peel_);
	HHVM_GIT2_V(return_value, reference) = result;
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_reference__alloc_symbolic,
	const String& name,
	const String& target)
{
	git_reference *result;
	auto return_value = req::make<Git2Resource>();

	result = git_reference__alloc_symbolic(name.c_str(), target.c_str());
	HHVM_GIT2_V(return_value, reference) = result;
	return Resource(return_value);
}

