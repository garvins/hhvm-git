<?hh


// --------------- attr.h ---------------

<<__Native>>
function git_attr_value(string $attr): int;

<<__Native>>
function git_attr_get(resource $repo,
                      int $flags,
                      string $path,
                      string $name): string;

<<__Native>>
function git_attr_get_many(resource $repo,
                           int $flags,
                           string $path,
                           int $num_attr,
                           array $names): string;

<<__Native>>
function git_attr_foreach(resource $repo,
                          int $flags,
                          string $path,
                          mixed $callback,
                          mixed $payload): int;

<<__Native>>
function git_attr_cache_flush(resource $repo): void;

<<__Native>>
function git_attr_add_macro(resource $repo,
                            string $name,
                            string $values): int;


// --------------- blame.h ---------------

<<__Native>>
function git_blame_get_hunk_count(resource $blame): int;

<<__Native>>
function git_blame_get_hunk_byindex(resource $blame,
                                    int $index): resource;

<<__Native>>
function git_blame_get_hunk_byline(resource $blame,
                                   int $lineno): resource;

<<__Native>>
function git_blame_file(resource $repo,
                        string $path,
                        resource $options): resource;

<<__Native>>
function git_blame_buffer(resource $reference,
                          string $buffer,
                          int $buffer_len): resource;

<<__Native>>
function git_blame_free(resource $blame): void;


// --------------- blob.h ---------------

<<__Native>>
function git_blob_lookup(resource $repo,
                         string $id): resource;

<<__Native>>
function git_blob_lookup_prefix(resource $repo,
                                string $id,
                                int $len): resource;

<<__Native>>
function git_blob_free(resource $blob): void;

<<__Native>>
function git_blob_id(resource $blob): string;

<<__Native>>
function git_blob_owner(resource $blob): resource;

<<__Native>>
function git_blob_rawcontent(resource $blob): string;

<<__Native>>
function git_blob_rawsize(resource $blob): int;

<<__Native>>
function git_blob_filtered_content(resource $blob,
                                   string $as_path,
                                   int $check_for_binary_data): resource;

<<__Native>>
function git_blob_create_fromworkdir(resource $repo,
                                     string $relative_path): string;

<<__Native>>
function git_blob_create_fromdisk(resource $repo,
                                  string $path): string;

<<__Native>>
function git_blob_create_fromchunks(resource $repo,
                                    string $hintpath,
                                    mixed $callback,
                                    mixed $payload): string;

<<__Native>>
function git_blob_create_frombuffer(resource $repo,
                                    mixed $buffer,
                                    int $len): string;

<<__Native>>
function git_blob_is_binary(resource $blob): int;


// --------------- branch.h ---------------

<<__Native>>
function git_branch_create(resource $repo,
                           string $branch_name,
                           resource $target,
                           int $force): resource;

<<__Native>>
function git_branch_delete(resource $branch): int;

<<__Native>>
function git_branch_iterator_new(resource $repo,
                                 int $list_flags): resource;

<<__Native>>
function git_branch_next(int $out_type,
                         resource $iter): resource;

<<__Native>>
function git_branch_iterator_free(resource $iter): void;

<<__Native>>
function git_branch_move(resource $branch,
                         string $new_branch_name,
                         int $force): resource;

<<__Native>>
function git_branch_lookup(resource $repo,
                           string $branch_name,
                           int $branch_type): resource;

<<__Native>>
function git_branch_name(resource $ref): string;

<<__Native>>
function git_branch_upstream(resource $branch): resource;

<<__Native>>
function git_branch_set_upstream(resource $branch,
                                 string $upstream_name): int;

<<__Native>>
function git_branch_upstream_name(int $buffer_size,
                                  resource $repo,
                                  string $canonical_branch_name): string;

<<__Native>>
function git_branch_is_head(resource $branch): int;

<<__Native>>
function git_branch_remote_name(int $buffer_size,
                                resource $repo,
                                string $canonical_branch_name): string;


// --------------- buffer.h ---------------

<<__Native>>
function git_buf_free(resource $buffer): void;

<<__Native>>
function git_buf_grow(resource $buffer,
                      int $target_size): int;

<<__Native>>
function git_buf_set(resource $buffer,
                     mixed $data,
                     int $datalen): int;


// --------------- checkout.h ---------------

<<__Native>>
function git_checkout_opts_new(): array;

<<__Native>>
function git_checkout_head(resource $repo,
                           resource $opts): int;

<<__Native>>
function git_checkout_index(resource $repo,
                            resource $index,
                            resource $opts): int;

<<__Native>>
function git_checkout_tree(resource $repo,
                           resource $treeish,
                           array $opts): int;


// --------------- clone.h ---------------

<<__Native>>
function git_clone(string $url,
                   string $local_path,
                   resource $options): resource;

<<__Native>>
function git_clone_into(resource $repo,
                        resource $remote,
                        resource $co_opts,
                        string $branch): int;


// --------------- commit.h ---------------

<<__Native>>
function git_commit_lookup(resource $repo,
                           string $id): resource;

<<__Native>>
function git_commit_lookup_prefix(resource $repo,
                                  string $id,
                                  int $len): resource;

<<__Native>>
function git_commit_free(resource $commit): void;

<<__Native>>
function git_commit_id(resource $commit): string;

<<__Native>>
function git_commit_owner(resource $commit): resource;

<<__Native>>
function git_commit_message_encoding(resource $commit): string;

<<__Native>>
function git_commit_message(resource $commit): string;

<<__Native>>
function git_commit_message_raw(resource $commit): string;

<<__Native>>
function git_commit_time(resource $commit): int;

<<__Native>>
function git_commit_time_offset(resource $commit): int;

<<__Native>>
function git_commit_committer(resource $commit): resource;

<<__Native>>
function git_commit_author(resource $commit): array;

<<__Native>>
function git_commit_raw_header(resource $commit): string;

<<__Native>>
function git_commit_tree(resource $commit): resource;

<<__Native>>
function git_commit_tree_id(resource $commit): string;

<<__Native>>
function git_commit_parentcount(resource $commit): int;

<<__Native>>
function git_commit_parent(resource $commit,
                           int $n): resource;

<<__Native>>
function git_commit_parent_id(resource $commit,
                              int $n): string;

<<__Native>>
function git_commit_nth_gen_ancestor(resource $commit,
                                     int $n): resource;

<<__Native>>
function git_commit_create(resource $repo,
                           string $update_ref,
                           array $author,
                           array $committer,
                           string $message_encoding,
                           string $message,
                           resource $tree,
                           array $parents): string;

<<__Native>>
function git_commit_create_v(resource $repo,
                             string $update_ref,
                             resource $author,
                             resource $committer,
                             string $message_encoding,
                             string $message,
                             resource $tree,
                             int $parent_count): string;


// --------------- common.h ---------------

<<__Native>>
function git_libgit2_version(int $major,
                             int $minor,
                             int $rev): void;

<<__Native>>
function git_libgit2_capabilities(): int;

<<__Native>>
function git_libgit2_opts(int $option): int;


// --------------- config.h ---------------

<<__Native>>
function git_config_find_global(int $length): string;

<<__Native>>
function git_config_find_xdg(int $length): string;

<<__Native>>
function git_config_find_system(int $length): string;

<<__Native>>
function git_config_open_default(): resource;

<<__Native>>
function git_config_new(): resource;

<<__Native>>
function git_config_add_file_ondisk(resource $cfg,
                                    string $path,
                                    int $level,
                                    int $force): int;

<<__Native>>
function git_config_open_ondisk(string $path): resource;

<<__Native>>
function git_config_open_level(resource $parent,
                               int $level): resource;

<<__Native>>
function git_config_open_global(resource $config): resource;

<<__Native>>
function git_config_refresh(resource $cfg): int;

<<__Native>>
function git_config_free(resource $cfg): void;

<<__Native>>
function git_config_get_entry(resource $cfg,
                              string $name): resource;

<<__Native>>
function git_config_get_int32(resource $cfg,
                              string $name): int;

<<__Native>>
function git_config_get_int64(resource $cfg,
                              string $name): int;

<<__Native>>
function git_config_get_bool(resource $cfg,
                             string $name): int;

<<__Native>>
function git_config_get_string(resource $cfg,
                               string $name): string;

<<__Native>>
function git_config_get_multivar_foreach(resource $cfg,
                                         string $name,
                                         string $regexp,
                                         mixed $callback,
                                         mixed $payload): int;

<<__Native>>
function git_config_multivar_iterator_new(resource $cfg,
                                          string $name,
                                          string $regexp): resource;

<<__Native>>
function git_config_next(resource $iter): resource;

<<__Native>>
function git_config_iterator_free(resource $iter): void;

<<__Native>>
function git_config_set_int32(resource $cfg,
                              string $name,
                              int $value): int;

<<__Native>>
function git_config_set_int64(resource $cfg,
                              string $name,
                              int $value): int;

<<__Native>>
function git_config_set_bool(resource $cfg,
                             string $name,
                             int $value): int;

<<__Native>>
function git_config_set_string(resource $cfg,
                               string $name,
                               string $value): int;

<<__Native>>
function git_config_set_multivar(resource $cfg,
                                 string $name,
                                 string $regexp,
                                 string $value): int;

<<__Native>>
function git_config_delete_entry(resource $cfg,
                                 string $name): int;

<<__Native>>
function git_config_delete_multivar(resource $cfg,
                                    string $name,
                                    string $regexp): int;

<<__Native>>
function git_config_foreach(resource $cfg,
                            mixed $callback,
                            mixed $payload): int;

<<__Native>>
function git_config_iterator_new(resource $cfg): resource;

<<__Native>>
function git_config_iterator_glob_new(resource $cfg,
                                      string $regexp): resource;

<<__Native>>
function git_config_foreach_match(resource $cfg,
                                  string $regexp,
                                  mixed $callback,
                                  mixed $payload): int;

<<__Native>>
function git_config_get_mapped(resource $cfg,
                               string $name,
                               resource $maps,
                               int $map_n): int;

<<__Native>>
function git_config_lookup_map_value(resource $maps,
                                     int $map_n,
                                     string $value): int;

<<__Native>>
function git_config_parse_bool(string $value): int;

<<__Native>>
function git_config_parse_int32(string $value): int;

<<__Native>>
function git_config_parse_int64(string $value): int;
 /*
<<__Native>>
function git_config_backend_foreach_match(resource $backend,
                                          string $regexp,
                                          int $cb,
                                          mixed $data): int;*/


// --------------- cred_helpers.h ---------------

<<__Native>>
function git_cred_userpass(string $url,
                           string $user_from_url,
                           int $allowed_types,
                           mixed $payload): resource;


// --------------- diff.h ---------------

<<__Native>>
function git_diff_free(resource $diff): void;

<<__Native>>
function git_diff_tree_to_tree(resource $repo,
                               resource $old_tree,
                               ?resource $new_tree = null,
                               ?array $opts = array()): resource;

<<__Native>>
function git_diff_tree_to_index(resource $repo,
                                resource $old_tree,
                                resource $index,
                                array $opts): resource;

<<__Native>>
function git_diff_index_to_workdir(resource $repo,
                                   resource $index,
                                   resource $opts): resource;

<<__Native>>
function git_diff_tree_to_workdir(resource $repo,
                                  resource $old_tree,
                                  resource $opts): resource;

<<__Native>>
function git_diff_tree_to_workdir_with_index(resource $repo,
                                             resource $old_tree,
                                             array $opts): resource;

<<__Native>>
function git_diff_merge(resource $onto,
                        resource $from): int;

<<__Native>>
function git_diff_find_similar(resource $diff,
                               resource $options): int;

<<__Native>>
function git_diff_options_init(resource $options,
                               int $version): int;

<<__Native>>
function git_diff_num_deltas(resource $diff): int;

<<__Native>>
function git_diff_num_deltas_of_type(resource $diff,
                                     int $type): int;

<<__Native>>
function git_diff_get_delta(resource $diff,
                            int $idx): resource;

<<__Native>>
function git_diff_is_sorted_icase(resource $diff): int;

<<__Native>>
function git_diff_foreach(resource $diff,
                          mixed $file_cb,
                          mixed $hunk_cb,
                          mixed $line_cb,
                          mixed $payload): int;

<<__Native>>
function git_diff_status_char(int $status): string;

<<__Native>>
function git_diff_print(resource $diff,
                        int $format,
                        mixed $print_cb,
                        ?mixed $payload): int;

<<__Native>>
function git_diff_blobs(resource $old_blob,
                        string $old_as_path,
                        resource $new_blob,
                        string $new_as_path,
                        resource $options,
                        mixed $file_cb,
                        mixed $hunk_cb,
                        mixed $line_cb,
                        mixed $payload): int;

<<__Native>>
function git_diff_blob_to_buffer(string $old_as_path,
                                 string $buffer,
                                 int $buffer_len,
                                 string $buffer_as_path,
                                 resource $options,
                                 mixed $file_cb,
                                 mixed $hunk_cb,
                                 mixed $line_cb,
                                 mixed $payload): resource;


// --------------- errors.h ---------------

<<__Native>>
function giterr_last(): array;

<<__Native>>
function giterr_clear(): void;

<<__Native>>
function giterr_detach(resource $cpy): int;

<<__Native>>
function giterr_set_str(int $error_class,
                        string $string): void;

<<__Native>>
function giterr_set_oom(): void;


// --------------- filter.h ---------------

<<__Native>>
function git_filter_list_load(resource $repo,
                              resource $blob,
                              string $path,
                              int $mode): resource;

<<__Native>>
function git_filter_list_apply_to_data(resource $filters,
                                       resource $in): resource;

<<__Native>>
function git_filter_list_apply_to_file(resource $filters,
                                       resource $repo,
                                       string $path): resource;

<<__Native>>
function git_filter_list_apply_to_blob(resource $filters,
                                       resource $blob): resource;

<<__Native>>
function git_filter_list_free(resource $filters): void;


// --------------- graph.h ---------------

<<__Native>>
function git_graph_ahead_behind(int $ahead,
                                int $behind,
                                resource $repo,
                                string $local,
                                string $upstream): int;


// --------------- ignore.h ---------------

<<__Native>>
function git_ignore_add_rule(resource $repo,
                             string $rules): int;

<<__Native>>
function git_ignore_clear_internal_rules(resource $repo): int;

<<__Native>>
function git_ignore_path_is_ignored(int $ignored,
                                    resource $repo,
                                    string $path): int;


// --------------- index.h ---------------

<<__Native>>
function git_index_open(string $index_path): resource;

<<__Native>>
function git_index_new(): resource;

<<__Native>>
function git_index_free(resource $index): void;

<<__Native>>
function git_index_owner(resource $index): resource;

<<__Native>>
function git_index_caps(resource $index): int;

<<__Native>>
function git_index_set_caps(resource $index,
                            int $caps): int;

<<__Native>>
function git_index_read(resource $index,
                        int $force): int;

<<__Native>>
function git_index_write(resource $index): int;

<<__Native>>
function git_index_path(resource $index): string;

<<__Native>>
function git_index_read_tree(resource $index,
                             resource $tree): int;

<<__Native>>
function git_index_write_tree(resource $index): string;

<<__Native>>
function git_index_write_tree_to(resource $index,
                                 resource $repo): string;

<<__Native>>
function git_index_entrycount(resource $index): int;

<<__Native>>
function git_index_clear(resource $index): void;

<<__Native>>
function git_index_get_byindex(resource $index,
                               int $n): resource;

<<__Native>>
function git_index_get_bypath(resource $index,
                              string $path,
                              int $stage): resource;

<<__Native>>
function git_index_remove(resource $index,
                          string $path,
                          int $stage): int;

<<__Native>>
function git_index_remove_directory(resource $index,
                                    string $dir,
                                    int $stage): int;

<<__Native>>
function git_index_add(resource $index,
                       array $source_entry): int;

<<__Native>>
function git_index_entry_stage(resource $entry): int;

<<__Native>>
function git_index_add_bypath(resource $index,
                              string $path): int;

<<__Native>>
function git_index_remove_bypath(resource $index,
                                 string $path): int;

<<__Native>>
function git_index_add_all(resource $index,
                           resource $pathspec,
                           int $flags,
                           mixed $callback,
                           mixed $payload): int;

<<__Native>>
function git_index_remove_all(resource $index,
                              resource $pathspec,
                              mixed $callback,
                              mixed $payload): int;

<<__Native>>
function git_index_update_all(resource $index,
                              resource $pathspec,
                              mixed $callback,
                              mixed $payload): int;

<<__Native>>
function git_index_find(int $at_pos,
                        resource $index,
                        string $path): int;

<<__Native>>
function git_index_conflict_add(resource $index,
                                resource $ancestor_entry,
                                resource $our_entry,
                                resource $their_entry): int;

<<__Native>>
function git_index_conflict_get(resource $index,
                                string $path): array;

<<__Native>>
function git_index_conflict_remove(resource $index,
                                   string $path): int;

<<__Native>>
function git_index_conflict_cleanup(resource $index): void;

<<__Native>>
function git_index_has_conflicts(resource $index): int;

<<__Native>>
function git_index_conflict_iterator_new(resource $index): resource;

<<__Native>>
function git_index_conflict_next(resource $iterator): array;

<<__Native>>
function git_index_conflict_iterator_free(resource $iterator): void;


// --------------- indexer.h ---------------

<<__Native>>
function git_indexer_new(string $path,
                         int $mode,
                         resource $odb,
                         mixed $progress_cb,
                         mixed $progress_cb_payload): resource;

<<__Native>>
function git_indexer_append(resource $idx,
                            mixed $data,
                            int $size,
                            resource $stats): int;

<<__Native>>
function git_indexer_commit(resource $idx,
                            resource $stats): int;

<<__Native>>
function git_indexer_hash(resource $idx): string;

<<__Native>>
function git_indexer_free(resource $idx): void;


// --------------- merge.h ---------------

<<__Native>>
function git_merge_base(resource $repo,
                        string $one,
                        string $two): string;

<<__Native>>
function git_merge_base_many(resource $repo,
                             int $length,
                             string $input_array): string;

<<__Native>>
function git_merge_head_from_ref(resource $repo,
                                 resource $ref): resource;

<<__Native>>
function git_merge_head_from_fetchhead(resource $repo,
                                       string $branch_name,
                                       string $remote_url,
                                       string $oid): resource;

<<__Native>>
function git_merge_head_from_oid(resource $repo,
                                 string $oid): resource;

<<__Native>>
function git_merge_head_free(resource $head): void;

<<__Native>>
function git_merge_trees(resource $repo,
                         resource $ancestor_tree,
                         resource $our_tree,
                         resource $their_tree,
                         resource $opts): resource;

<<__Native>>
function git_merge(resource $repo,
                   resource $their_heads,
                   array $opts): resource;

<<__Native>>
function git_merge_result_is_uptodate(resource $merge_result): int;

<<__Native>>
function git_merge_result_is_fastforward(resource $merge_result): int;

<<__Native>>
function git_merge_result_fastforward_oid(resource $merge_result): string;

<<__Native>>
function git_merge_result_free(resource $merge_result): void;


// --------------- message.h ---------------

<<__Native>>
function git_message_prettify(int $out_size,
                              string $message,
                              int $strip_comments): string;


// --------------- notes.h ---------------

<<__Native>>
function git_note_iterator_new(resource $repo,
                               string $notes_ref): resource;

<<__Native>>
function git_note_iterator_free(resource $it): void;

<<__Native>>
function git_note_next(string $annotated_id,
                       resource $it): string;

<<__Native>>
function git_note_read(resource $repo,
                       string $notes_ref,
                       string $oid): resource;

<<__Native>>
function git_note_message(resource $note): string;

<<__Native>>
function git_note_oid(resource $note): string;

<<__Native>>
function git_note_create(resource $repo,
                         resource $author,
                         resource $committer,
                         string $notes_ref,
                         string $oid,
                         string $note,
                         int $force): string;

<<__Native>>
function git_note_remove(resource $repo,
                         string $notes_ref,
                         resource $author,
                         resource $committer,
                         string $oid): int;

<<__Native>>
function git_note_free(resource $note): void;

<<__Native>>
function git_note_default_ref(resource $repo): string;

<<__Native>>
function git_note_foreach(resource $repo,
                          string $notes_ref,
                          mixed $note_cb,
                          mixed $payload): int;


// --------------- object.h ---------------

<<__Native>>
function git_object_lookup(resource $repo,
                           string $id,
                           int $type): resource;

<<__Native>>
function git_object_lookup_prefix(resource $repo,
                                  string $id,
                                  int $len,
                                  int $type): resource;

<<__Native>>
function git_object_lookup_bypath(resource $treeish,
                                  string $path,
                                  int $type): resource;

<<__Native>>
function git_object_id(resource $obj): string;

<<__Native>>
function git_object_type(resource $obj): int;

<<__Native>>
function git_object_owner(resource $obj): resource;

<<__Native>>
function git_object_free(resource $object): void;

<<__Native>>
function git_object_type2string(int $type): string;

<<__Native>>
function git_object_string2type(string $str): int;

<<__Native>>
function git_object_typeisloose(int $type): int;

<<__Native>>
function git_object__size(int $type): int;

<<__Native>>
function git_object_peel(resource $object,
                         int $target_type): resource;

<<__Native>>
function git_object_dup(resource $source): resource;


// --------------- odb.h ---------------

<<__Native>>
function git_odb_new(): resource;

<<__Native>>
function git_odb_open(string $objects_dir): resource;

<<__Native>>
function git_odb_add_disk_alternate(resource $odb,
                                    string $path): int;

<<__Native>>
function git_odb_free(resource $db): void;

<<__Native>>
function git_odb_read(resource $db,
                      string $id): resource;

<<__Native>>
function git_odb_read_prefix(resource $db,
                             string $short_id,
                             int $len): resource;

<<__Native>>
function git_odb_read_header(int $type_out,
                             resource $db,
                             string $id): int;

<<__Native>>
function git_odb_exists(resource $db,
                        string $id): int;

<<__Native>>
function git_odb_refresh(resource $db): int;

<<__Native>>
function git_odb_foreach(resource $db,
                         mixed $cb,
                         mixed $payload): int;

<<__Native>>
function git_odb_write(resource $odb,
                       mixed $data,
                       int $len,
                       int $type): string;

<<__Native>>
function git_odb_open_wstream(resource $db,
                              int $size,
                              int $type): resource;

<<__Native>>
function git_odb_stream_write(resource $stream,
                              string $buffer,
                              int $len): int;

<<__Native>>
function git_odb_stream_finalize_write(resource $stream): string;

<<__Native>>
function git_odb_stream_read(resource $stream,
                             string $buffer,
                             int $len): int;

<<__Native>>
function git_odb_stream_free(resource $stream): void;

<<__Native>>
function git_odb_open_rstream(resource $db,
                              string $oid): resource;

<<__Native>>
function git_odb_write_pack(resource $db,
                            mixed $progress_cb,
                            mixed $progress_payload): resource;

<<__Native>>
function git_odb_hash(mixed $data,
                      int $len,
                      int $type): string;

<<__Native>>
function git_odb_hashfile(string $path,
                          int $type): string;

<<__Native>>
function git_odb_object_dup(resource $source): resource;

<<__Native>>
function git_odb_object_free(resource $object): void;

<<__Native>>
function git_odb_object_id(resource $object): string;

<<__Native>>
function git_odb_object_data(resource $object): void;

<<__Native>>
function git_odb_object_size(resource $object): int;

<<__Native>>
function git_odb_object_type(resource $object): int;

<<__Native>>
function git_odb_add_backend(resource $odb,
                             resource $backend,
                             int $priority): int;

<<__Native>>
function git_odb_add_alternate(resource $odb,
                               resource $backend,
                               int $priority): int;

<<__Native>>
function git_odb_num_backends(resource $odb): int;

<<__Native>>
function git_odb_get_backend(resource $odb,
                             int $pos): resource;


// --------------- odb_backend.h ---------------

<<__Native>>
function git_odb_backend_pack(string $objects_dir): resource;

<<__Native>>
function git_odb_backend_loose(string $objects_dir,
                               int $compression_level,
                               int $do_fsync,
                               int $dir_mode,
                               int $file_mode): resource;

<<__Native>>
function git_odb_backend_one_pack(string $index_file): resource;


// --------------- oid.h ---------------

<<__Native>>
function git_oid_fromstr(string $str): string;

<<__Native>>
function git_oid_fromstrp(string $str): string;

<<__Native>>
function git_oid_fromstrn(string $str,
                          int $length): string;

<<__Native>>
function git_oid_fromraw(string $raw): string;

<<__Native>>
function git_oid_fmt(string $id): string;

<<__Native>>
function git_oid_nfmt(int $n,
                      string $id): string;

<<__Native>>
function git_oid_pathfmt(string $id): string;

<<__Native>>
function git_oid_allocfmt(string $id): string;

<<__Native>>
function git_oid_tostr(int $n,
                       string $id): string;

<<__Native>>
function git_oid_cpy(string $src): string;

<<__Native>>
function git_oid_cmp(string $a,
                     string $b): int;

<<__Native>>
function git_oid_ncmp(string $a,
                      string $b,
                      int $len): int;

<<__Native>>
function git_oid_streq(string $id,
                       string $str): int;

<<__Native>>
function git_oid_strcmp(string $id,
                        string $str): int;

<<__Native>>
function git_oid_iszero(string $id): int;

<<__Native>>
function git_oid_shorten_new(int $min_length): resource;

<<__Native>>
function git_oid_shorten_add(resource $os,
                             string $text_id): int;

<<__Native>>
function git_oid_shorten_free(resource $os): void;


// --------------- pack.h ---------------

<<__Native>>
function git_packbuilder_new(resource $repo): resource;

<<__Native>>
function git_packbuilder_set_threads(resource $pb,
                                     int $n): int;

<<__Native>>
function git_packbuilder_insert(resource $pb,
                                string $id,
                                string $name): int;

<<__Native>>
function git_packbuilder_insert_tree(resource $pb,
                                     string $id): int;

<<__Native>>
function git_packbuilder_insert_commit(resource $pb,
                                       string $id): int;

<<__Native>>
function git_packbuilder_write(resource $pb,
                               string $path,
                               int $mode,
                               mixed $progress_cb,
                               mixed $progress_cb_payload): int;

<<__Native>>
function git_packbuilder_hash(resource $pb): string;

<<__Native>>
function git_packbuilder_foreach(resource $pb,
                                 mixed $cb,
                                 mixed $payload): int;

<<__Native>>
function git_packbuilder_object_count(resource $pb): int;

<<__Native>>
function git_packbuilder_written(resource $pb): int;

<<__Native>>
function git_packbuilder_set_callbacks(resource $pb,
                                       mixed $progress_cb,
                                       mixed $progress_cb_payload): int;

<<__Native>>
function git_packbuilder_free(resource $pb): void;


// --------------- patch.h ---------------

<<__Native>>
function git_patch_from_diff(resource $diff,
                             int $idx): resource;

<<__Native>>
function git_patch_from_blobs(resource $old_blob,
                              string $old_as_path,
                              resource $new_blob,
                              string $new_as_path,
                              resource $opts): resource;

<<__Native>>
function git_patch_from_blob_and_buffer(resource $old_blob,
                                        string $old_as_path,
                                        string $buffer,
                                        int $buffer_len,
                                        string $buffer_as_path,
                                        resource $opts): resource;

<<__Native>>
function git_patch_free(resource $patch): void;

<<__Native>>
function git_patch_get_delta(resource $patch): resource;

<<__Native>>
function git_patch_num_hunks(resource $patch): int;

<<__Native>>
function git_patch_line_stats(resource $patch): int;

<<__Native>>
function git_patch_get_hunk(int $lines_in_hunk,
                            resource $patch,
                            int $hunk_idx): resource;

<<__Native>>
function git_patch_num_lines_in_hunk(resource $patch,
                                     int $hunk_idx): int;

<<__Native>>
function git_patch_get_line_in_hunk(resource $patch,
                                    int $hunk_idx,
                                    int $line_of_hunk): resource;

<<__Native>>
function git_patch_size(resource $patch,
                        int $include_context,
                        int $include_hunk_headers,
                        int $include_file_headers): int;

<<__Native>>
function git_patch_print(resource $patch,
                         mixed $print_cb,
                         mixed $payload): int;

<<__Native>>
function git_patch_to_str(array $string,
                          resource $patch): int;


// --------------- pathspec.h ---------------

<<__Native>>
function git_pathspec_new(resource $pathspec): resource;

<<__Native>>
function git_pathspec_free(resource $ps): void;

<<__Native>>
function git_pathspec_matches_path(resource $ps,
                                   int $flags,
                                   string $path): int;

<<__Native>>
function git_pathspec_match_workdir(resource $repo,
                                    int $flags,
                                    resource $ps): resource;

<<__Native>>
function git_pathspec_match_index(resource $index,
                                  int $flags,
                                  resource $ps): resource;

<<__Native>>
function git_pathspec_match_tree(resource $tree,
                                 int $flags,
                                 resource $ps): resource;

<<__Native>>
function git_pathspec_match_diff(resource $diff,
                                 int $flags,
                                 resource $ps): resource;

<<__Native>>
function git_pathspec_match_list_free(resource $m): void;

<<__Native>>
function git_pathspec_match_list_entrycount(resource $m): int;

<<__Native>>
function git_pathspec_match_list_entry(resource $m,
                                       int $pos): string;

<<__Native>>
function git_pathspec_match_list_diff_entry(resource $m,
                                            int $pos): resource;

<<__Native>>
function git_pathspec_match_list_failed_entrycount(resource $m): int;

<<__Native>>
function git_pathspec_match_list_failed_entry(resource $m,
                                              int $pos): string;


// --------------- push.h ---------------

<<__Native>>
function git_push_new(resource $remote): resource;

<<__Native>>
function git_push_set_options(resource $push,
                              resource $opts): int;

<<__Native>>
function git_push_set_callbacks(resource $push,
                                mixed $pack_progress_cb,
                                mixed $pack_progress_cb_payload,
                                mixed $transfer_progress_cb,
                                mixed $transfer_progress_cb_payload): int;

<<__Native>>
function git_push_add_refspec(resource $push,
                              string $refspec): int;

<<__Native>>
function git_push_update_tips(resource $push): int;

<<__Native>>
function git_push_finish(resource $push): int;

<<__Native>>
function git_push_unpack_ok(resource $push): int;

<<__Native>>
function git_push_status_foreach(resource $push,
                                 mixed $cb,
                                 mixed $data): int;

<<__Native>>
function git_push_free(resource $push): void;


// --------------- refdb.h ---------------

<<__Native>>
function git_refdb_new(resource $repo): resource;

<<__Native>>
function git_refdb_open(resource $repo): resource;

<<__Native>>
function git_refdb_compress(resource $refdb): int;

<<__Native>>
function git_refdb_free(resource $refdb): void;


// --------------- reflog.h ---------------

<<__Native>>
function git_reflog_read(resource $repo,
                         string $name): resource;

<<__Native>>
function git_reflog_write(resource $reflog): int;

<<__Native>>
function git_reflog_append(resource $reflog,
                           string $id,
                           resource $committer,
                           string $msg): int;

<<__Native>>
function git_reflog_append_to(resource $repo,
                              string $name,
                              string $id,
                              resource $committer,
                              string $msg): int;

<<__Native>>
function git_reflog_rename(resource $repo,
                           string $old_name,
                           string $name): int;

<<__Native>>
function git_reflog_delete(resource $repo,
                           string $name): int;

<<__Native>>
function git_reflog_entrycount(resource $reflog): int;

<<__Native>>
function git_reflog_entry_byindex(resource $reflog,
                                  int $idx): resource;

<<__Native>>
function git_reflog_drop(resource $reflog,
                         int $idx,
                         int $rewrite_previous_entry): int;

<<__Native>>
function git_reflog_entry_id_old(resource $entry): string;

<<__Native>>
function git_reflog_entry_id_new(resource $entry): string;

<<__Native>>
function git_reflog_entry_committer(resource $entry): resource;

<<__Native>>
function git_reflog_entry_message(resource $entry): string;

<<__Native>>
function git_reflog_free(resource $reflog): void;


// --------------- refs.h ---------------

<<__Native>>
function git_reference_lookup(resource $repo,
                              string $name): resource;

<<__Native>>
function git_reference_name_to_id(resource $repo,
                                  string $name): string;

<<__Native>>
function git_reference_dwim(resource $repo,
                            string $shorthand): resource;

<<__Native>>
function git_reference_symbolic_create(resource $repo,
                                       string $name,
                                       string $target,
                                       int $force): resource;

<<__Native>>
function git_reference_create(resource $repo,
                              string $name,
                              string $id,
                              int $force): resource;

<<__Native>>
function git_reference_target(resource $ref): string;

<<__Native>>
function git_reference_target_peel(resource $ref): string;

<<__Native>>
function git_reference_symbolic_target(resource $ref): string;

<<__Native>>
function git_reference_type(resource $ref): int;

<<__Native>>
function git_reference_name(resource $ref): string;

<<__Native>>
function git_reference_resolve(resource $ref): resource;

<<__Native>>
function git_reference_owner(resource $ref): resource;

<<__Native>>
function git_reference_symbolic_set_target(resource $ref,
                                           string $target): resource;

<<__Native>>
function git_reference_set_target(resource $ref,
                                  string $id): resource;

<<__Native>>
function git_reference_rename(resource $ref,
                              string $new_name,
                              int $force): resource;

<<__Native>>
function git_reference_delete(resource $ref): int;

<<__Native>>
function git_reference_list(resource $array,
                            resource $repo): int;

<<__Native>>
function git_reference_foreach(resource $repo,
                               mixed $callback,
                               mixed $payload): int;

<<__Native>>
function git_reference_foreach_name(resource $repo,
                                    mixed $callback,
                                    mixed $payload): int;

<<__Native>>
function git_reference_free(resource $ref): void;

<<__Native>>
function git_reference_cmp(resource $ref1,
                           resource $ref2): int;

<<__Native>>
function git_reference_iterator_new(resource $repo): resource;

<<__Native>>
function git_reference_iterator_glob_new(resource $repo,
                                         string $glob): resource;

<<__Native>>
function git_reference_next(resource $iter): mixed;

<<__Native>>
function git_reference_next_name(resource $iter): string;

<<__Native>>
function git_reference_iterator_free(resource $iter): void;

<<__Native>>
function git_reference_foreach_glob(resource $repo,
                                    string $glob,
                                    mixed $callback,
                                    mixed $payload): int;

<<__Native>>
function git_reference_has_log(resource $ref): int;

<<__Native>>
function git_reference_is_branch(resource $ref): int;

<<__Native>>
function git_reference_is_remote(resource $ref): int;

<<__Native>>
function git_reference_is_tag(resource $ref): int;

<<__Native>>
function git_reference_normalize_name(int $buffer_size,
                                      string $name,
                                      int $flags): string;

<<__Native>>
function git_reference_peel(resource $ref,
                            int $type): resource;

<<__Native>>
function git_reference_is_valid_name(string $refname): int;

<<__Native>>
function git_reference_shorthand(resource $ref): string;


// --------------- refspec.h ---------------

<<__Native>>
function git_refspec_src(resource $refspec): string;

<<__Native>>
function git_refspec_dst(resource $refspec): string;

<<__Native>>
function git_refspec_string(resource $refspec): string;

<<__Native>>
function git_refspec_force(resource $refspec): int;

<<__Native>>
function git_refspec_direction(resource $spec): int;

<<__Native>>
function git_refspec_src_matches(resource $refspec,
                                 string $refname): int;

<<__Native>>
function git_refspec_dst_matches(resource $refspec,
                                 string $refname): int;

<<__Native>>
function git_refspec_transform(int $outlen,
                               resource $spec,
                               string $name): string;

<<__Native>>
function git_refspec_rtransform(int $outlen,
                                resource $spec,
                                string $name): string;


// --------------- remote.h ---------------

<<__Native>>
function git_remote_create(resource $repo,
                           string $name,
                           string $url): resource;

<<__Native>>
function git_remote_create_with_fetchspec(resource $repo,
                                          string $name,
                                          string $url,
                                          string $fetch): resource;

<<__Native>>
function git_remote_create_inmemory(resource $repo,
                                    string $fetch,
                                    string $url): resource;

<<__Native>>
function git_remote_load(resource $repo,
                         string $name): resource;

<<__Native>>
function git_remote_save(resource $remote): int;

<<__Native>>
function git_remote_owner(resource $remote): resource;

<<__Native>>
function git_remote_name(resource $remote): string;

<<__Native>>
function git_remote_url(resource $remote): string;

<<__Native>>
function git_remote_pushurl(resource $remote): string;

<<__Native>>
function git_remote_set_url(resource $remote,
                            string $url): int;

<<__Native>>
function git_remote_set_pushurl(resource $remote,
                                string $url): int;

<<__Native>>
function git_remote_add_fetch(resource $remote,
                              string $refspec): int;

<<__Native>>
function git_remote_get_fetch_refspecs(resource $array,
                                       resource $remote): int;

<<__Native>>
function git_remote_set_fetch_refspecs(resource $remote,
                                       resource $array): int;

<<__Native>>
function git_remote_add_push(resource $remote,
                             string $refspec): int;

<<__Native>>
function git_remote_get_push_refspecs(resource $array,
                                      resource $remote): int;

<<__Native>>
function git_remote_set_push_refspecs(resource $remote,
                                      resource $array): int;

<<__Native>>
function git_remote_clear_refspecs(resource $remote): void;

<<__Native>>
function git_remote_refspec_count(resource $remote): int;

<<__Native>>
function git_remote_get_refspec(resource $remote,
                                int $n): resource;

<<__Native>>
function git_remote_connect(resource $remote,
                            int $direction): int;

<<__Native>>
function git_remote_ls(int $size,
                       resource $remote): resource;

<<__Native>>
function git_remote_download(resource $remote): int;

<<__Native>>
function git_remote_connected(resource $remote): int;

<<__Native>>
function git_remote_stop(resource $remote): void;

<<__Native>>
function git_remote_disconnect(resource $remote): void;

<<__Native>>
function git_remote_free(resource $remote): void;

<<__Native>>
function git_remote_update_tips(resource $remote): int;

<<__Native>>
function git_remote_fetch(resource $remote): int;

<<__Native>>
function git_remote_valid_url(string $url): int;

<<__Native>>
function git_remote_supported_url(string $url): int;

<<__Native>>
function git_remote_list(resource $repo): resource;

<<__Native>>
function git_remote_check_cert(resource $remote,
                               int $check): void;

<<__Native>>
function git_remote_set_transport(resource $remote,
                                  resource $transport): int;

<<__Native>>
function git_remote_set_callbacks(resource $remote,
                                  array $callbacks): int;

<<__Native>>
function git_remote_stats(resource $remote): resource;

<<__Native>>
function git_remote_autotag(resource $remote): int;

<<__Native>>
function git_remote_set_autotag(resource $remote,
                                int $value): void;

<<__Native>>
function git_remote_rename(resource $remote,
                           string $new_name,
                           mixed $callback,
                           mixed $payload): int;

<<__Native>>
function git_remote_update_fetchhead(resource $remote): int;

<<__Native>>
function git_remote_set_update_fetchhead(resource $remote,
                                         int $value): void;

<<__Native>>
function git_remote_is_valid_name(string $remote_name): int;


// --------------- repository.h ---------------

<<__Native>>
function git_repository_open(string $path): resource;

<<__Native>>
function git_repository_wrap_odb(resource $odb): resource;

<<__Native>>
function git_repository_discover(int $path_size,
                                 string $start_path,
                                 int $across_fs,
                                 string $ceiling_dirs): string;

<<__Native>>
function git_repository_open_ext(string $path,
                                 int $flags,
                                 string $ceiling_dirs): resource;

<<__Native>>
function git_repository_open_bare(string $bare_path): resource;

<<__Native>>
function git_repository_free(resource $repo): void;

<<__Native>>
function git_repository_init(string $path,
                             int $is_bare): resource;

<<__Native>>
function git_repository_init_ext(string $repo_path,
                                 resource $opts): resource;

<<__Native>>
function git_repository_head(resource $repo): resource;

<<__Native>>
function git_repository_head_detached(resource $repo): int;

<<__Native>>
function git_repository_head_unborn(resource $repo): int;

<<__Native>>
function git_repository_is_empty(resource $repo): int;

<<__Native>>
function git_repository_path(resource $repo): string;

<<__Native>>
function git_repository_workdir(resource $repo): string;

<<__Native>>
function git_repository_set_workdir(resource $repo,
                                    string $workdir,
                                    int $update_gitlink): int;

<<__Native>>
function git_repository_is_bare(resource $repo): int;

<<__Native>>
function git_repository_config(resource $repo): resource;

<<__Native>>
function git_repository_odb(resource $repo): resource;

<<__Native>>
function git_repository_refdb(resource $repo): resource;

<<__Native>>
function git_repository_index(resource $repo): resource;

<<__Native>>
function git_repository_message(int $len,
                                resource $repo): string;

<<__Native>>
function git_repository_message_remove(resource $repo): int;

<<__Native>>
function git_repository_merge_cleanup(resource $repo): int;

<<__Native>>
function git_repository_fetchhead_foreach(resource $repo,
                                          mixed $callback,
                                          mixed $payload): int;

<<__Native>>
function git_repository_mergehead_foreach(resource $repo,
                                          mixed $callback,
                                          mixed $payload): int;

<<__Native>>
function git_repository_hashfile(resource $repo,
                                 string $path,
                                 int $type,
                                 string $as_path): string;

<<__Native>>
function git_repository_set_head(resource $repo,
                                 string $refname): int;

<<__Native>>
function git_repository_set_head_detached(resource $repo,
                                          string $commitish): int;

<<__Native>>
function git_repository_detach_head(resource $repo): int;

<<__Native>>
function git_repository_state(resource $repo): int;

<<__Native>>
function git_repository_set_namespace(resource $repo,
                                      string $nmspace): int;

<<__Native>>
function git_repository_get_namespace(resource $repo): string;

<<__Native>>
function git_repository_is_shallow(resource $repo): int;


// --------------- reset.h ---------------

<<__Native>>
function git_reset(resource $repo,
                   resource $target,
                   int $reset_type): int;

<<__Native>>
function git_reset_default(resource $repo,
                           resource $target,
                           resource $pathspecs): int;


// --------------- revparse.h ---------------

<<__Native>>
function git_revparse_single(resource $repo,
                             string $spec): resource;

<<__Native>>
function git_revparse_ext(resource $repo,
                          string $spec): resource;

<<__Native>>
function git_revparse(resource $revspec,
                      resource $repo,
                      string $spec): int;


// --------------- revwalk.h ---------------

<<__Native>>
function git_revwalk_new(resource $repo): resource;

<<__Native>>
function git_revwalk_reset(resource $walker): void;

<<__Native>>
function git_revwalk_push(resource $walk,
                          string $id): int;

<<__Native>>
function git_revwalk_push_glob(resource $walk,
                               string $glob): int;

<<__Native>>
function git_revwalk_push_head(resource $walk): int;

<<__Native>>
function git_revwalk_hide(resource $walk,
                          string $commit_id): int;

<<__Native>>
function git_revwalk_hide_glob(resource $walk,
                               string $glob): int;

<<__Native>>
function git_revwalk_hide_head(resource $walk): int;

<<__Native>>
function git_revwalk_push_ref(resource $walk,
                              string $refname): int;

<<__Native>>
function git_revwalk_hide_ref(resource $walk,
                              string $refname): int;

<<__Native>>
function git_revwalk_next(resource $walk): string;

<<__Native>>
function git_revwalk_sorting(resource $walk,
                             int $sort_mode): void;

<<__Native>>
function git_revwalk_push_range(resource $walk,
                                string $range): int;

<<__Native>>
function git_revwalk_simplify_first_parent(resource $walk): void;

<<__Native>>
function git_revwalk_free(resource $walk): void;

<<__Native>>
function git_revwalk_repository(resource $walk): resource;


// --------------- signature.h ---------------

<<__Native>>
function git_signature_new(string $name,
                           string $email,
                           int $time,
                           int $offset): resource;

<<__Native>>
function git_signature_now(string $name,
                           string $email): array;

<<__Native>>
function git_signature_default(resource $repo): resource;

<<__Native>>
function git_signature_dup(resource $sig): resource;

<<__Native>>
function git_signature_free(resource $sig): void;


// --------------- stash.h ---------------

<<__Native>>
function git_stash_save(resource $repo,
                        resource $stasher,
                        string $message,
                        int $flags): string;

<<__Native>>
function git_stash_foreach(resource $repo,
                           mixed $callback,
                           mixed $payload): int;

<<__Native>>
function git_stash_drop(resource $repo,
                        int $index): int;


// --------------- status.h ---------------

<<__Native>>
function git_status_foreach(resource $repo,
                            mixed $callback,
                            mixed $payload): int;

<<__Native>>
function git_status_foreach_ext(resource $repo,
                                resource $opts,
                                mixed $callback,
                                mixed $payload): int;

<<__Native>>
function git_status_file(int $status_flags,
                         resource $repo,
                         string $path): int;

<<__Native>>
function git_status_list_new(resource $repo,
                             resource $opts): resource;

<<__Native>>
function git_status_list_entrycount(resource $statuslist): int;

<<__Native>>
function git_status_byindex(resource $statuslist,
                            int $idx): resource;

<<__Native>>
function git_status_list_free(resource $statuslist): void;

<<__Native>>
function git_status_should_ignore(int $ignored,
                                  resource $repo,
                                  string $path): int;


// --------------- strarray.h ---------------

<<__Native>>
function git_strarray_free(resource $array): void;

<<__Native>>
function git_strarray_copy(resource $tgt,
                           resource $src): int;


// --------------- submodule.h ---------------

<<__Native>>
function git_submodule_lookup(resource $repo,
                              string $name): resource;

<<__Native>>
function git_submodule_foreach(resource $repo,
                               int $cb,
                               mixed $payload): int;

<<__Native>>
function git_submodule_add_setup(resource $repo,
                                 string $url,
                                 string $path,
                                 int $use_gitlink): resource;

<<__Native>>
function git_submodule_add_finalize(resource $submodule): int;

<<__Native>>
function git_submodule_add_to_index(resource $submodule,
                                    int $write_index): int;

<<__Native>>
function git_submodule_save(resource $submodule): int;

<<__Native>>
function git_submodule_owner(resource $submodule): resource;

<<__Native>>
function git_submodule_name(resource $submodule): string;

<<__Native>>
function git_submodule_path(resource $submodule): string;

<<__Native>>
function git_submodule_url(resource $submodule): string;

<<__Native>>
function git_submodule_set_url(resource $submodule,
                               string $url): int;

<<__Native>>
function git_submodule_index_id(resource $submodule): string;

<<__Native>>
function git_submodule_head_id(resource $submodule): string;

<<__Native>>
function git_submodule_wd_id(resource $submodule): string;

<<__Native>>
function git_submodule_ignore(resource $submodule): int;

<<__Native>>
function git_submodule_set_ignore(resource $submodule,
                                  int $ignore): int;

<<__Native>>
function git_submodule_update(resource $submodule): int;

<<__Native>>
function git_submodule_set_update(resource $submodule,
                                  int $update): int;

<<__Native>>
function git_submodule_fetch_recurse_submodules(resource $submodule): int;

<<__Native>>
function git_submodule_set_fetch_recurse_submodules(resource $submodule,
                                                    int $fetch_recurse_submodules): int;

<<__Native>>
function git_submodule_init(resource $submodule,
                            int $overwrite): int;

<<__Native>>
function git_submodule_sync(resource $submodule): int;

<<__Native>>
function git_submodule_open(resource $submodule): resource;

<<__Native>>
function git_submodule_reload(resource $submodule): int;

<<__Native>>
function git_submodule_reload_all(resource $repo): int;

<<__Native>>
function git_submodule_status(int $status,
                              resource $submodule): int;

<<__Native>>
function git_submodule_location(int $location_status,
                                resource $submodule): int;


// --------------- sys_commit.h ---------------

<<__Native>>
function git_commit_create_from_oids(resource $repo,
                                     string $update_ref,
                                     resource $author,
                                     resource $committer,
                                     string $message_encoding,
                                     string $message,
                                     string $tree,
                                     int $parent_count,
                                     string $parents): string;


// --------------- sys_config.h ---------------

<<__Native>>
function git_config_add_backend(resource $cfg,
                                resource $file,
                                int $level,
                                int $force): int;


// --------------- sys_filter.h ---------------

<<__Native>>
function git_filter_lookup(string $name): resource;

<<__Native>>
function git_filter_list_new(resource $repo,
                             int $mode): resource;

<<__Native>>
function git_filter_list_push(resource $fl,
                              resource $filter,
                              mixed $payload): int;

<<__Native>>
function git_filter_list_length(resource $fl): int;

<<__Native>>
function git_filter_source_repo(resource $src): resource;

<<__Native>>
function git_filter_source_path(resource $src): string;

<<__Native>>
function git_filter_source_filemode(resource $src): int;

<<__Native>>
function git_filter_source_id(resource $src): string;

<<__Native>>
function git_filter_source_mode(resource $src): int;

<<__Native>>
function git_filter_register(string $name,
                             resource $filter,
                             int $priority): int;

<<__Native>>
function git_filter_unregister(string $name): int;


// --------------- sys_index.h ---------------

<<__Native>>
function git_index_name_entrycount(resource $index): int;

<<__Native>>
function git_index_name_get_byindex(resource $index,
                                    int $n): resource;

<<__Native>>
function git_index_name_add(resource $index,
                            string $ancestor,
                            string $ours,
                            string $theirs): int;

<<__Native>>
function git_index_name_clear(resource $index): void;

<<__Native>>
function git_index_reuc_entrycount(resource $index): int;

<<__Native>>
function git_index_reuc_find(int $at_pos,
                             resource $index,
                             string $path): int;

<<__Native>>
function git_index_reuc_get_bypath(resource $index,
                                   string $path): resource;

<<__Native>>
function git_index_reuc_get_byindex(resource $index,
                                    int $n): resource;

<<__Native>>
function git_index_reuc_add(resource $index,
                            string $path,
                            int $ancestor_mode,
                            string $ancestor_id,
                            int $our_mode,
                            string $our_id,
                            int $their_mode,
                            string $their_id): int;

<<__Native>>
function git_index_reuc_remove(resource $index,
                               int $n): int;

<<__Native>>
function git_index_reuc_clear(resource $index): void;


// --------------- sys_odb_backend.h ---------------

<<__Native>>
function git_odb_backend_malloc(resource $backend,
                                int $len): void;


// --------------- sys_refdb_backend.h ---------------

<<__Native>>
function git_refdb_backend_fs(resource $repo): resource;

<<__Native>>
function git_refdb_set_backend(resource $refdb,
                               resource $backend): int;


// --------------- sys_reflog.h ---------------

<<__Native>>
function git_reflog_entry__alloc(): resource;

<<__Native>>
function git_reflog_entry__free(resource $entry): void;


// --------------- sys_refs.h ---------------

<<__Native>>
function git_reference__alloc(string $name,
                              string $oid,
                              string $peel): resource;

<<__Native>>
function git_reference__alloc_symbolic(string $name,
                                       string $target): resource;


// --------------- sys_repository.h ---------------

<<__Native>>
function git_repository_new(): resource;

<<__Native>>
function git_repository__cleanup(resource $repo): void;

<<__Native>>
function git_repository_reinit_filesystem(resource $repo,
                                          int $recurse_submodules): int;

<<__Native>>
function git_repository_set_config(resource $repo,
                                   resource $config): void;

<<__Native>>
function git_repository_set_odb(resource $repo,
                                resource $odb): void;

<<__Native>>
function git_repository_set_refdb(resource $repo,
                                  resource $refdb): void;

<<__Native>>
function git_repository_set_index(resource $repo,
                                  resource $index): void;


// --------------- tag.h ---------------

<<__Native>>
function git_tag_lookup(resource $repo,
                        string $id): resource;

<<__Native>>
function git_tag_lookup_prefix(resource $repo,
                               string $id,
                               int $len): resource;

<<__Native>>
function git_tag_free(resource $tag): void;

<<__Native>>
function git_tag_id(resource $tag): string;

<<__Native>>
function git_tag_owner(resource $tag): resource;

<<__Native>>
function git_tag_target(resource $tag): resource;

<<__Native>>
function git_tag_target_id(resource $tag): string;

<<__Native>>
function git_tag_target_type(resource $tag): int;

<<__Native>>
function git_tag_name(resource $tag): string;

<<__Native>>
function git_tag_tagger(resource $tag): resource;

<<__Native>>
function git_tag_message(resource $tag): string;

<<__Native>>
function git_tag_create(resource $repo,
                        string $tag_name,
                        resource $target,
                        resource $tagger,
                        string $message,
                        int $force): string;

<<__Native>>
function git_tag_annotation_create(resource $repo,
                                   string $tag_name,
                                   resource $target,
                                   resource $tagger,
                                   string $message): string;

<<__Native>>
function git_tag_create_frombuffer(resource $repo,
                                   string $buffer,
                                   int $force): string;

<<__Native>>
function git_tag_create_lightweight(resource $repo,
                                    string $tag_name,
                                    resource $target,
                                    int $force): string;

<<__Native>>
function git_tag_delete(resource $repo,
                        string $tag_name): int;

<<__Native>>
function git_tag_list(resource $tag_names,
                      resource $repo): int;

<<__Native>>
function git_tag_list_match(resource $tag_names,
                            string $pattern,
                            resource $repo): int;

<<__Native>>
function git_tag_foreach(resource $repo,
                         mixed $callback,
                         mixed $payload): int;

<<__Native>>
function git_tag_peel(resource $tag): resource;


// --------------- threads.h ---------------

<<__Native>>
function git_threads_init(): int;

<<__Native>>
function git_threads_shutdown(): void;


// --------------- trace.h ---------------

<<__Native>>
function git_trace_set(int $level,
                       mixed $cb): int;


// --------------- transport.h ---------------

<<__Native>>
function git_cred_has_username(resource $cred): int;

<<__Native>>
function git_cred_userpass_plaintext_new(string $username,
                                         string $password): resource;

<<__Native>>
function git_cred_ssh_key_new(string $username,
                              string $publickey,
                              string $privatekey,
                              string $passphrase): resource;

<<__Native>>
function git_cred_ssh_custom_new(string $username,
                                 string $publickey,
                                 int $publickey_len,
                                 mixed $sign_fn,
                                 mixed $sign_data): resource;

<<__Native>>
function git_cred_default_new(): resource;

<<__Native>>
function git_transport_new(resource $owner,
                           string $url): resource;

<<__Native>>
function git_transport_register(string $prefix,
                                int $priority,
                                mixed $cb,
                                mixed $param): int;

<<__Native>>
function git_transport_unregister(string $prefix,
                                  int $priority): int;

<<__Native>>
function git_transport_dummy(resource $owner,
                             mixed $payload): resource;

<<__Native>>
function git_transport_local(resource $owner,
                             mixed $payload): resource;

<<__Native>>
function git_transport_smart(resource $owner,
                             mixed $payload): resource;

<<__Native>>
function git_smart_subtransport_http(resource $owner): resource;

<<__Native>>
function git_smart_subtransport_git(resource $owner): resource;

<<__Native>>
function git_smart_subtransport_ssh(resource $owner): resource;


// --------------- tree.h ---------------

<<__Native>>
function git_tree_lookup(resource $repo,
                         string $id): resource;

<<__Native>>
function git_tree_lookup_prefix(resource $repo,
                                string $id,
                                int $len): resource;

<<__Native>>
function git_tree_free(resource $tree): void;

<<__Native>>
function git_tree_id(resource $tree): string;

<<__Native>>
function git_tree_owner(resource $tree): resource;

<<__Native>>
function git_tree_entrycount(resource $tree): int;

<<__Native>>
function git_tree_entry_byname(resource $tree,
                               string $filename): resource;

<<__Native>>
function git_tree_entry_byindex(resource $tree,
                                int $idx): resource;

<<__Native>>
function git_tree_entry_byoid(resource $tree,
                              string $oid): resource;

<<__Native>>
function git_tree_entry_bypath(resource $root,
                               string $path): resource;

<<__Native>>
function git_tree_entry_dup(resource $entry): resource;

<<__Native>>
function git_tree_entry_free(resource $entry): void;

<<__Native>>
function git_tree_entry_name(resource $entry): string;

<<__Native>>
function git_tree_entry_id(resource $entry): string;

<<__Native>>
function git_tree_entry_type(resource $entry): int;

<<__Native>>
function git_tree_entry_filemode(resource $entry): int;

<<__Native>>
function git_tree_entry_filemode_raw(resource $entry): int;

<<__Native>>
function git_tree_entry_cmp(resource $e1,
                            resource $e2): int;

<<__Native>>
function git_tree_entry_to_object(resource $repo,
                                  resource $entry): resource;

<<__Native>>
function git_treebuilder_create(resource $source): resource;

<<__Native>>
function git_treebuilder_clear(resource $bld): void;

<<__Native>>
function git_treebuilder_entrycount(resource $bld): int;

<<__Native>>
function git_treebuilder_free(resource $bld): void;

<<__Native>>
function git_treebuilder_get(resource $bld,
                             string $filename): resource;

<<__Native>>
function git_treebuilder_insert(resource $bld,
                                string $filename,
                                string $id,
                                int $filemode): resource;

<<__Native>>
function git_treebuilder_remove(resource $bld,
                                string $filename): int;

<<__Native>>
function git_treebuilder_filter(resource $bld,
                                mixed $filter,
                                mixed $payload): void;

<<__Native>>
function git_treebuilder_write(string $id,
                               resource $repo,
                               resource $bld): int;

<<__Native>>
function git_tree_walk(resource $tree,
                       int $mode,
                       mixed $callback,
                       mixed $payload): int;
