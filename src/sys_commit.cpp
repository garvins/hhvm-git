/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#include "sys_commit.h"

using namespace HPHP;

int64_t HHVM_FUNCTION(git_commit_create_from_oids,
	const String& oid,
	const Resource& repo,
	const String& update_ref,
	const Resource& author,
	const Resource& committer,
	const String& message_encoding,
	const String& message,
	const String& tree,
	int64_t parent_count,
	const String& parents)
{
	int result;
	int64_t return_value;

	git_oid oid_;
	git_oid tree_;
	git_oid parents_;

	if (git_oid_fromstrn(&oid_, oid.c_str(), oid.length())) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error->message);
	}
	auto repo_ = dyn_cast<Git2Resource>(repo);
	auto author_ = dyn_cast<Git2Resource>(author);
	auto committer_ = dyn_cast<Git2Resource>(committer);
	if (git_oid_fromstr(&tree_, tree.c_str()) != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}
	if (git_oid_fromstr(&parents_, parents.c_str()) != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}
    // todo
	/*result = git_commit_create_from_oids(oid_, HHVM_GIT2_V(repo_, repository), update_ref.c_str(), HHVM_GIT2_V(author_, signature), HHVM_GIT2_V(committer_, signature), message_encoding.c_str(), message.c_str(), tree_, (int) parent_count, parents_); */
	return_value = (int64_t) result;
	return return_value;
}

