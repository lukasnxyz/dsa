const std = @import("std");

const Allocator = std.mem.Allocator;

fn mergeSortedList(allocator: Allocator, list1: []const i32, list2: []const i32) !std.ArrayList(i32) {
    var i: usize = 0;
    var j: usize = 0;
    var merged = std.ArrayList(i32).init(allocator);
    errdefer merged.deinit();

    while (i < list1.len and j < list2.len) {
        if (list1[i] < list2[j]) {
            try merged.append(list1[i]);
            i += 1;
        } else {
            try merged.append(list2[j]);
            j += 1;
        }
    }

    return merged;
}

pub fn main() !void {
    var gpa = std.heap.GeneralPurposeAllocator(.{}){};
    defer _ = gpa.deinit();
    const allocator = gpa.allocator();

    const list1 = [_]i32{ 1, 3, 5, 7, 9 };
    const list2 = [_]i32{ 2, 4, 6, 8, 10 };

    const merged_list = try mergeSortedList(allocator, &list1, &list2);
    defer merged_list.deinit();
    for (merged_list.items) |item|
        std.debug.print("{} ", .{item});
    std.debug.print("\n", .{});
}
