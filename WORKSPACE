load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

# TCMalloc
http_archive(
    name = "com_google_tcmalloc",
    sha256 = "fcfa15de5a2719aca2f9c066b64419e7e361969ed5d04b64e89ff5c465d55a00",
    strip_prefix = "tcmalloc-0e8cc551f2719ffd413cfd3947925dc59686f675",
    urls = ["https://github.com/google/tcmalloc/archive/0e8cc551f2719ffd413cfd3947925dc59686f675.zip"],
)

# Load a recent version of skylib in case our dependencies have obsolete
# versions. This is needed for bazel 6 compatibility.
http_archive(
    name = "bazel_skylib",  # 2022-09-01
    sha256 = "4756ab3ec46d94d99e5ed685d2d24aece484015e45af303eb3a11cab3cdc2e71",
    strip_prefix = "bazel-skylib-1.3.0",
    urls = ["https://github.com/bazelbuild/bazel-skylib/archive/refs/tags/1.3.0.zip"],
)

# Abseil
http_archive(
    name = "com_google_absl",
    sha256 = "faa6a7c544fc77f04c1ffdee829325781a3fe77d87b45b3ac3ae62abfd06782a",
    strip_prefix = "abseil-cpp-7152f9bc3cbf039ec96f18545b73948a95c9e7ec",
    urls = ["https://github.com/abseil/abseil-cpp/archive/7152f9bc3cbf039ec96f18545b73948a95c9e7ec.zip"],
)

# GoogleTest/GoogleMock framework. Used by most unit-tests.
http_archive(
    name = "com_google_googletest",  # 2023-06-15T14:52:03Z
    sha256 = "6bd1fa9e61bfa1cce07a22a4274bc1143733c17803458e5332a09ae10c994b4e",
    strip_prefix = "googletest-4a1a299b206ba250a4318f74938ea67c75c3c0c9",
    urls = ["https://github.com/google/googletest/archive/4a1a299b206ba250a4318f74938ea67c75c3c0c9.zip"],
)

# RE2
http_archive(
    name = "com_googlesource_code_re2",
    sha256 = "ef516fb84824a597c4d5d0d6d330daedb18363b5a99eda87d027e6bdd9cba299",
    strip_prefix = "re2-03da4fc0857c285e3a26782f6bc8931c4c950df4",
    urls = ["https://github.com/google/re2/archive/03da4fc0857c285e3a26782f6bc8931c4c950df4.tar.gz"],
)

# Google benchmark.
http_archive(
    name = "com_github_google_benchmark",
    sha256 = "ae52561357b670255c0518c0ab481a8949105e1d724bb191e3c8e30454cf53c4",
    strip_prefix = "benchmark-16c6ad83aa46d01b0b12a32c8ed0360bb83d151b",
    urls = ["https://github.com/google/benchmark/archive/16c6ad83aa46d01b0b12a32c8ed0360bb83d151b.zip"],
)

# C++ rules for Bazel.
http_archive(
    name = "rules_cc",  # 2021-05-14T14:51:14Z
    sha256 = "91286857db13f2f7f12242017b9f5714a85038b1df62b926cb75b7610cf40c1b",
    strip_prefix = "rules_cc-7f0992b0bd47d5b24076c2d022ba1819cc8641e4",
    urls = ["https://github.com/bazelbuild/rules_cc/archive/7f0992b0bd47d5b24076c2d022ba1819cc8641e4.zip"],
)

# Python rules
#
# This is explicitly added to work around
# https://github.com/bazelbuild/rules_fuzzing/issues/207
# and https://github.com/google/tcmalloc/issues/127
http_archive(
    name = "rules_python",
    sha256 = "c03246c11efd49266e8e41e12931090b613e12a59e6f55ba2efd29a7cb8b4258",
    strip_prefix = "rules_python-0.11.0",
    urls = ["https://github.com/bazelbuild/rules_python/archive/refs/tags/0.11.0.tar.gz"],
)

# Proto rules for Bazel and Protobuf
http_archive(
    name = "com_google_protobuf",
    sha256 = "9ca59193fcfe52c54e4c2b4584770acd1a6528fc35efad363f8513c224490c50",
    strip_prefix = "protobuf-13d559beb6967033a467a7517c35d8ad970f8afb",
    urls = ["https://github.com/protocolbuffers/protobuf/archive/13d559beb6967033a467a7517c35d8ad970f8afb.zip"],
)

load("@com_google_protobuf//:protobuf_deps.bzl", "protobuf_deps")

protobuf_deps()

http_archive(
    name = "rules_proto",
    sha256 = "66bfdf8782796239d3875d37e7de19b1d94301e8972b3cbd2446b332429b4df1",
    strip_prefix = "rules_proto-4.0.0",
    urls = [
        "https://mirror.bazel.build/github.com/bazelbuild/rules_proto/archive/refs/tags/4.0.0.tar.gz",
        "https://github.com/bazelbuild/rules_proto/archive/refs/tags/4.0.0.tar.gz",
    ],
)

load("@rules_proto//proto:repositories.bzl", "rules_proto_dependencies", "rules_proto_toolchains")

rules_proto_dependencies()

rules_proto_toolchains()

# Fuzzing
http_archive(
    name = "rules_fuzzing",
    sha256 = "a5734cb42b1b69395c57e0bbd32ade394d5c3d6afbfe782b24816a96da24660d",
    strip_prefix = "rules_fuzzing-0.1.1",
    urls = ["https://github.com/bazelbuild/rules_fuzzing/archive/v0.1.1.zip"],
)

# Protobuf
load("@rules_fuzzing//fuzzing:repositories.bzl", "rules_fuzzing_dependencies")

rules_fuzzing_dependencies()

load("@rules_fuzzing//fuzzing:init.bzl", "rules_fuzzing_init")

rules_fuzzing_init()

# Hedron's Compile Commands Extractor for Bazel
# https://github.com/hedronvision/bazel-compile-commands-extractor
http_archive(
    name = "hedron_compile_commands",
    sha256 = "3cd0e49f0f4a6d406c1d74b53b7616f5e24f5fd319eafc1bf8eee6e14124d115",
    strip_prefix = "bazel-compile-commands-extractor-3dddf205a1f5cde20faf2444c1757abe0564ff4c",

    # Replace the commit hash in both places (below) with the latest, rather than using the stale one here.
    # Even better, set up Renovate and let it do the work for you (see "Suggestion: Updates" in the README).
    url = "https://github.com/hedronvision/bazel-compile-commands-extractor/archive/3dddf205a1f5cde20faf2444c1757abe0564ff4c.tar.gz",
    # When you first run this tool, it'll recommend a sha256 hash to put here with a message like: "DEBUG: Rule 'hedron_compile_commands' indicated that a canonical reproducible form can be obtained by modifying arguments sha256 = ..."
)

load("@hedron_compile_commands//:workspace_setup.bzl", "hedron_compile_commands_setup")

hedron_compile_commands_setup()

http_archive(
    name = "rules_foreign_cc",
    sha256 = "61b74a99496470a27989b396b8331d93aba6c6cf21997533d6df3848eb5a095c",
    strip_prefix = "rules_foreign_cc-26c77008307c80a90fabc8fe3f7a72b961120a84",
    url = "https://github.com/bazelbuild/rules_foreign_cc/archive/26c77008307c80a90fabc8fe3f7a72b961120a84.tar.gz",
)

load("@rules_foreign_cc//foreign_cc:repositories.bzl", "rules_foreign_cc_dependencies")

rules_foreign_cc_dependencies()

# Liburing
http_archive(
    name = "com_github_liburing",
    build_file = "@//:liburing.BUILD",
    sha256 = "71dfb3c22b7916a26de1203225249ddc6a39f4291908463cbc54b8a107819de7",
    strip_prefix = "liburing-33a326b64769c01dd5ff0e11e510641055c9354d",
    url = "https://github.com/axboe/liburing/archive/33a326b64769c01dd5ff0e11e510641055c9354d.zip",
)

# Boring SSL
http_archive(
    name = "com_github_google_boringssl",
    sha256 = "ef05634781d25271e2b57c46c4bf7a91213698fc67285a4a1dbc8d7943a38f94",
    strip_prefix = "boringssl-e7e254fe468ec43ec72b716ee154f47091d62393",
    url = "https://github.com/google/boringssl/archive/e7e254fe468ec43ec72b716ee154f47091d62393.zip",
)

# buildifier is written in Go and hence needs rules_go to be built.
# See https://github.com/bazelbuild/rules_go for the up to date setup instructions.
http_archive(
    name = "io_bazel_rules_go",
    sha256 = "6dc2da7ab4cf5d7bfc7c949776b1b7c733f05e56edc4bcd9022bb249d2e2a996",
    urls = [
        "https://mirror.bazel.build/github.com/bazelbuild/rules_go/releases/download/v0.39.1/rules_go-v0.39.1.zip",
        "https://github.com/bazelbuild/rules_go/releases/download/v0.39.1/rules_go-v0.39.1.zip",
    ],
)

load("@io_bazel_rules_go//go:deps.bzl", "go_rules_dependencies")

go_rules_dependencies()

load("@io_bazel_rules_go//go:deps.bzl", "go_register_toolchains")

go_register_toolchains(version = "1.20.3")

http_archive(
    name = "bazel_gazelle",
    sha256 = "727f3e4edd96ea20c29e8c2ca9e8d2af724d8c7778e7923a854b2c80952bc405",
    urls = [
        "https://mirror.bazel.build/github.com/bazelbuild/bazel-gazelle/releases/download/v0.30.0/bazel-gazelle-v0.30.0.tar.gz",
        "https://github.com/bazelbuild/bazel-gazelle/releases/download/v0.30.0/bazel-gazelle-v0.30.0.tar.gz",
    ],
)

load("@bazel_gazelle//:deps.bzl", "gazelle_dependencies")

# If you use WORKSPACE.bazel, use the following line instead of the bare gazelle_dependencies():
# gazelle_dependencies(go_repository_default_config = "@//:WORKSPACE.bazel")
gazelle_dependencies()

http_archive(
    name = "com_github_bazelbuild_buildtools",
    sha256 = "ae34c344514e08c23e90da0e2d6cb700fcd28e80c02e23e4d5715dddcb42f7b3",
    strip_prefix = "buildtools-4.2.2",
    urls = [
        "https://github.com/bazelbuild/buildtools/archive/refs/tags/4.2.2.tar.gz",
    ],
)
