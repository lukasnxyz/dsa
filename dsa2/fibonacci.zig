const std = @import("std");

const Allocator = std.mem.Allocator;

fn fib(allocator: Allocator, n: usize) ![]const u32 {
    var ret = try allocator.alloc(u32, n);
    const init = [_]u32{ 0, 1, 1 };
    @memcpy(ret[0..@min(3, n)], init[0..@min(3, n)]);
    for (2..n) |i| {
        ret[i] = ret[i - 1] + ret[i - 2];
    }

    return ret;
}

fn comptimeFib(comptime n: usize) [n]u32 {
    var ret: [n]u32 = undefined;
    const init = [_]u32{ 0, 1, 1 };
    comptime var i: usize = 0;
    inline while (i < @min(3, n)) : (i += 1) {
        ret[i] = init[i];
    }

    inline while (i < n) : (i += 1) {
        ret[i] = ret[i - 1] + ret[i - 2];
    }
    return ret;
}

pub fn main() !void {
    //var arena = std.heap.ArenaAllocator.init(std.heap.page_allocator);
    //defer arena.deinit();
    //const allocator = arena.allocator();

    //const fib_nums = fib(allocator, 10);
    const fib_nums = comptime comptimeFib(10);
    std.debug.print("{any}\n", .{fib_nums});
}
