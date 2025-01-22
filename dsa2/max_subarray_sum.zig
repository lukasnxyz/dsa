const std = @import("std");

const Allocator = std.mem.Allocator;

const MaxSubarrSumInf = struct {
    from: usize = 0,
    to: usize = 0,
    max: i32 = 0,
};

// - going through input scanline style
// - runtime theta O(n) (this is down from O(n*2^n) and O(n^3))
fn maxSubarrSum(allocator: Allocator, writer: anytype, arr: []const i32) !*MaxSubarrSumInf {
    const n = arr.len;
    var ctotal: i32 = 0;
    var from: usize = 0;
    var i: usize = 0;
    var info: *MaxSubarrSumInf = try allocator.create(MaxSubarrSumInf);

    while (i < n) : (i += 1) {
        try writer.print("{any}\n", .{arr[from .. i + 1]});
        ctotal = ctotal + arr[i];
        if (ctotal < 0) {
            ctotal = 0;
            from = i + 1;
        }
        if (ctotal > info.max) {
            info.max = ctotal;
            info.from = from;
            info.to = i;
        }
    }

    return info;
}

pub fn main() !void {
    const writer = std.io.getStdOut().writer();
    var gpa = std.heap.GeneralPurposeAllocator(.{}){};
    defer _ = gpa.deinit();
    const allocator = gpa.allocator();

    const arr = [_]i32{ 4, -5, 4, 2, -3 };

    const minfo = try maxSubarrSum(allocator, writer, &arr);
    defer allocator.destroy(minfo);
    try writer.print("max sum [{}, {}]: {}\n", .{ minfo.from, minfo.to, minfo.max });
}
