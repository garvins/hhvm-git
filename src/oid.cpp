/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#include "oid.h"

using namespace HPHP;

String HHVM_FUNCTION(git_oid_fromstr,
	const String& str)
{
	int result;
	char return_value[GIT_OID_HEXSZ+1] = {0};

	git_oid out;

	result = git_oid_fromstr(&out, str.c_str());

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	git_oid_fmt(return_value, &out);
	return String(return_value);
}

String HHVM_FUNCTION(git_oid_fromstrp,
	const String& str)
{
	int result;
	char return_value[GIT_OID_HEXSZ+1] = {0};

	git_oid out;

	result = git_oid_fromstrp(&out, str.c_str());

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	git_oid_fmt(return_value, &out);
	return String(return_value);
}

String HHVM_FUNCTION(git_oid_fromstrn,
	const String& str,
	int64_t length)
{
	int result;
	char return_value[GIT_OID_HEXSZ+1] = {0};

	git_oid out;

	result = git_oid_fromstrn(&out, str.c_str(), (size_t) length);

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	git_oid_fmt(return_value, &out);
	return String(return_value);
}

String HHVM_FUNCTION(git_oid_fromraw,
	const String& raw)
{
	char return_value[GIT_OID_HEXSZ+1] = {0};

	git_oid out;

    // todo
	/*git_oid_fromraw(out, raw.c_str());
	git_oid_fmt(return_value, out);*/
	return String(return_value);
}

String HHVM_FUNCTION(git_oid_fmt,
	const String& id)
{
	String return_value;

	char out;
	git_oid id_;

	if (git_oid_fromstr(&id_, id.c_str()) != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	git_oid_fmt(&out, &id_);

	if (&out != NULL) {
		return_value = String(&out);
	} else {
		return_value = "";
	}

	return return_value;
}

String HHVM_FUNCTION(git_oid_nfmt,
	int64_t n,
	const String& id)
{
	String return_value;

	char out;
	git_oid id_;

	if (git_oid_fromstr(&id_, id.c_str()) != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	git_oid_nfmt(&out, (size_t) n, &id_);

	if (&out != NULL) {
		return_value = String(&out);
	} else {
		return_value = "";
	}

	return return_value;
}

String HHVM_FUNCTION(git_oid_pathfmt,
	const String& id)
{
	String return_value;

	char out;
	git_oid id_;

	if (git_oid_fromstr(&id_, id.c_str()) != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	git_oid_pathfmt(&out, &id_);

	if (&out != NULL) {
		return_value = String(&out);
	} else {
		return_value = "";
	}

	return return_value;
}

String HHVM_FUNCTION(git_oid_allocfmt,
	const String& id)
{
	char *result;
	String return_value;

	git_oid id_;

	if (git_oid_fromstr(&id_, id.c_str()) != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	result = git_oid_allocfmt(&id_);

	if (result != NULL) {
		return_value = String(result);
	} else {
		return_value = "";
	}

	return return_value;
}

String HHVM_FUNCTION(git_oid_tostr,
	int64_t n,
	const String& id)
{
	String return_value;

	char out;
	git_oid id_;

	if (git_oid_fromstr(&id_, id.c_str()) != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	git_oid_tostr(&out, (size_t) n, &id_);

	if (&out != NULL) {
		return_value = String(&out);
	} else {
		return_value = "";
	}

	return return_value;
}

String HHVM_FUNCTION(git_oid_cpy,
	const String& src)
{
	char return_value[GIT_OID_HEXSZ+1] = {0};

	git_oid out;
	git_oid src_;

	if (git_oid_fromstr(&src_, src.c_str()) != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	git_oid_cpy(&out, &src_);
	git_oid_fmt(return_value, &out);
	return String(return_value);
}

int64_t HHVM_FUNCTION(git_oid_cmp,
	const String& a,
	const String& b)
{
	int result;
	int64_t return_value;

	git_oid a_;
	git_oid b_;

	if (git_oid_fromstr(&a_, a.c_str()) != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}
	if (git_oid_fromstr(&b_, b.c_str()) != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	result = git_oid_cmp(&a_, &b_);

	// todo handle possible error

	return_value = (int64_t) result;
	return return_value;
}

// todo git_oid_equal not parsed because of GIT_INLINE

int64_t HHVM_FUNCTION(git_oid_ncmp,
	const String& a,
	const String& b,
	int64_t len)
{
	int result;
	int64_t return_value;

	git_oid a_;
	git_oid b_;

	if (git_oid_fromstr(&a_, a.c_str()) != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}
	if (git_oid_fromstr(&b_, b.c_str()) != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	result = git_oid_ncmp(&a_, &b_, (size_t) len);
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_oid_streq,
	const String& id,
	const String& str)
{
	int result;
	int64_t return_value;

	git_oid id_;

	if (git_oid_fromstr(&id_, id.c_str()) != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	result = git_oid_streq(&id_, str.c_str());

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_oid_strcmp,
	const String& id,
	const String& str)
{
	int result;
	int64_t return_value;

	git_oid id_;

	if (git_oid_fromstr(&id_, id.c_str()) != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	result = git_oid_strcmp(&id_, str.c_str());
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_oid_iszero,
	const String& id)
{
	int result;
	int64_t return_value;

	git_oid id_;

	if (git_oid_fromstr(&id_, id.c_str()) != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	result = git_oid_iszero(&id_);

	if (result != GIT_OK && result != 1) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	return_value = (int64_t) result;
	return return_value;
}

Resource HHVM_FUNCTION(git_oid_shorten_new,
	int64_t min_length)
{
	git_oid_shorten *result;
	auto return_value = req::make<Git2Resource>();

	result = git_oid_shorten_new((size_t) min_length);
	HHVM_GIT2_V(return_value, oid_shorten) = result;
	return Resource(return_value);
}

int64_t HHVM_FUNCTION(git_oid_shorten_add,
	const Resource& os,
	const String& text_id)
{
	int result;
	int64_t return_value;

	auto os_ = dyn_cast<Git2Resource>(os);

	result = git_oid_shorten_add(HHVM_GIT2_V(os_, oid_shorten), text_id.c_str());

	if (result < 0) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	return_value = (int64_t) result;
	return return_value;
}

void HHVM_FUNCTION(git_oid_shorten_free,
	const Resource& os)
{
	auto os_ = dyn_cast<Git2Resource>(os);

	git_oid_shorten_free(HHVM_GIT2_V(os_, oid_shorten));
}

