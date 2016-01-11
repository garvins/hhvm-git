/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#include "hphp/system/systemlib.h"

#include "notes.h"

using namespace HPHP;

Resource HHVM_FUNCTION(git_note_iterator_new,
	const Resource& repo,
	const String& notes_ref)
{
	auto return_value = req::make<Git2Resource>();

	git_note_iterator *out = NULL;

	auto repo_ = dyn_cast<Git2Resource>(repo);

	git_note_iterator_new(&out, HHVM_GIT2_V(repo_, repository), notes_ref.c_str());
	HHVM_GIT2_V(return_value, note_iterator) = out;
	return Resource(return_value);
}

void HHVM_FUNCTION(git_note_iterator_free,
	const Resource& it)
{

	auto it_ = dyn_cast<Git2Resource>(it);

	git_note_iterator_free(HHVM_GIT2_V(it_, note_iterator));
}

String HHVM_FUNCTION(git_note_next,
	const String& annotated_id,
	const Resource& it)
{
	char *return_value;

	git_oid note_id;
	git_oid *annotated_id_ = NULL;

	if (git_oid_fromstrn(annotated_id_, annotated_id.c_str(), annotated_id.length())) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error->message);
	}
	auto it_ = dyn_cast<Git2Resource>(it);

	git_note_next(&note_id, annotated_id_, HHVM_GIT2_V(it_, note_iterator));
	git_oid_fmt(return_value, &note_id);
	return String(return_value);
}

Resource HHVM_FUNCTION(git_note_read,
	const Resource& repo,
	const String& notes_ref,
	const String& oid)
{
	auto return_value = req::make<Git2Resource>();

	git_note *out = NULL;
	git_oid *oid_ = NULL;

	auto repo_ = dyn_cast<Git2Resource>(repo);
	if (git_oid_fromstrn(oid_, oid.c_str(), oid.length())) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error->message);
	}

	git_note_read(&out, HHVM_GIT2_V(repo_, repository), notes_ref.c_str(), oid_);
	HHVM_GIT2_V(return_value, note) = out;
	return Resource(return_value);
}

String HHVM_FUNCTION(git_note_message,
	const Resource& note)
{
	const char *result;
	String return_value;

	auto note_ = dyn_cast<Git2Resource>(note);

	result = git_note_message(HHVM_GIT2_V(note_, note));
	return_value = String(result);
	return return_value;
}

String HHVM_FUNCTION(git_note_oid,
	const Resource& note)
{
	const git_oid *result;
	char *return_value;

	auto note_ = dyn_cast<Git2Resource>(note);

	result = git_note_oid(HHVM_GIT2_V(note_, note));
	git_oid_fmt(return_value, result);
	return String(return_value);
}

String HHVM_FUNCTION(git_note_create,
	const Resource& repo,
	const Resource& author,
	const Resource& committer,
	const String& notes_ref,
	const String& oid,
	const String& note,
	int64_t force)
{
	char *return_value;

	git_oid out;
	git_oid *oid_ = NULL;

	auto repo_ = dyn_cast<Git2Resource>(repo);
	auto author_ = dyn_cast<Git2Resource>(author);
	auto committer_ = dyn_cast<Git2Resource>(committer);
	if (git_oid_fromstrn(oid_, oid.c_str(), oid.length())) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error->message);
	}

	git_note_create(&out, HHVM_GIT2_V(repo_, repository), HHVM_GIT2_V(author_, signature), HHVM_GIT2_V(committer_, signature), notes_ref.c_str(), oid_, note.c_str(), (int) force);
	git_oid_fmt(return_value, &out);
	return String(return_value);
}

int64_t HHVM_FUNCTION(git_note_remove,
	const Resource& repo,
	const String& notes_ref,
	const Resource& author,
	const Resource& committer,
	const String& oid)
{
	int result;
	int64_t return_value;

	git_oid *oid_ = NULL;

	auto repo_ = dyn_cast<Git2Resource>(repo);
	auto author_ = dyn_cast<Git2Resource>(author);
	auto committer_ = dyn_cast<Git2Resource>(committer);
	if (git_oid_fromstrn(oid_, oid.c_str(), oid.length())) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error->message);
	}

	result = git_note_remove(HHVM_GIT2_V(repo_, repository), notes_ref.c_str(), HHVM_GIT2_V(author_, signature), HHVM_GIT2_V(committer_, signature), oid_);
	return_value = (int64_t) result;
	return return_value;
}

void HHVM_FUNCTION(git_note_free,
	const Resource& note)
{

	auto note_ = dyn_cast<Git2Resource>(note);

	git_note_free(HHVM_GIT2_V(note_, note));
}

String HHVM_FUNCTION(git_note_default_ref,
	const Resource& repo)
{
	String return_value;

	const char *out = NULL;

	auto repo_ = dyn_cast<Git2Resource>(repo);

	git_note_default_ref(&out, HHVM_GIT2_V(repo_, repository));
	return_value = String(out);
	return return_value;
}

int64_t HHVM_FUNCTION(git_note_foreach,
	const Resource& repo,
	const String& notes_ref,
	const Variant& note_cb,
	const Variant& payload)
{
	int result;
	int64_t return_value;

	git_note_foreach_cb note_cb_ = NULL;
	void *payload_ = NULL;

	auto repo_ = dyn_cast<Git2Resource>(repo);
	note_cb_ = NULL;

	result = git_note_foreach(HHVM_GIT2_V(repo_, repository), notes_ref.c_str(), /* todo */ note_cb_, payload_);
	return_value = (int64_t) result;
	return return_value;
}

