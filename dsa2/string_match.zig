const std = @import("std");

const Allocator = std.mem.Allocator;
const print = std.debug.print;

// pre-computation takes O(m) time
fn smpreCompute(allocator: Allocator, pattern: []const u8) ![]usize {
    const len = pattern.len;
    var failure: []usize = try allocator.alloc(usize, len);
    errdefer allocator.free(failure);

    failure[0] = 0;
    var i: usize = 1;
    var j: usize = 0;

    while (i < len) : (i += 1) {
        if (pattern[i] == pattern[j]) {
            j += 1;
            failure[i] = j;
        } else if (j > 0) {
            j = failure[j - 1];
            i -= 1;
        } else {
            failure[i] = 0;
        }
    }

    for (pattern) |p| print("{c} ", .{p});
    print("\n", .{});
    for (failure) |f| print("{} ", .{f});
    print("\n", .{});

    return failure;
}

// knuth-morris-pratt algorithm
// runtime: O(n+ m) => O(n)
pub fn stringMatch(allocator: Allocator, text: []const u8, pattern: []const u8) !?usize {
    if (pattern.len == 0) return 0;
    if (text.len < pattern.len) return null;

    const failure = try smpreCompute(allocator, pattern);
    defer allocator.free(failure);

    var t: usize = 0;
    var p: usize = 0;
    const n = text.len;
    const m = pattern.len;

    while (t < n) {
        if (text[t] == pattern[p]) {
            t += 1;
            p += 1;
            if (p == m) {
                return t - p;
            }
        } else if (p > 0) {
            p = failure[p - 1];
        } else {
            t += 1;
        }
    }

    return null;
}

pub fn main() !void {
    var gpa = std.heap.GeneralPurposeAllocator(.{}){};
    defer _ = gpa.deinit();
    const allocator = gpa.allocator();

    const text = "abbabbabbabaabbaaba";
    const pattern = "abaabba";

    if (try stringMatch(allocator, text, pattern)) |index| {
        print("string matched at index {}!\n", .{index});
    } else {
        print("pattern not found!\n", .{});
    }
}
