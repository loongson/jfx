/*
 * Copyright (C) 2017 Igalia S.L.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#pragma once

#include "GridPositionsResolver.h"
#include "LayoutUnit.h"

namespace WebCore {

class RenderBox;
class RenderElement;
class RenderGrid;

enum GridAxis { GridRowAxis, GridColumnAxis };

namespace GridLayoutFunctions {

LayoutUnit computeMarginLogicalSizeForChild(const RenderGrid&, GridTrackSizingDirection, const RenderBox&);
LayoutUnit marginLogicalSizeForChild(const RenderGrid&, GridTrackSizingDirection, const RenderBox&);
bool isOrthogonalChild(const RenderGrid&, const RenderBox&);
bool isOrthogonalParent(const RenderGrid&, const RenderElement& parent);
bool isAspectRatioBlockSizeDependentChild(const RenderBox&);
GridTrackSizingDirection flowAwareDirectionForChild(const RenderGrid&, const RenderBox&, GridTrackSizingDirection);
GridTrackSizingDirection flowAwareDirectionForParent(const RenderGrid&, const RenderElement& parent, GridTrackSizingDirection);
bool hasOverridingContainingBlockContentSizeForChild(const RenderBox&, GridTrackSizingDirection);
std::optional<LayoutUnit> overridingContainingBlockContentSizeForChild(const RenderBox&, GridTrackSizingDirection);

bool isFlippedDirection(const RenderGrid&, GridTrackSizingDirection);
bool isSubgridReversedDirection(const RenderGrid&, GridTrackSizingDirection outerDirection, const RenderGrid& subgrid);

}

} // namespace WebCore

