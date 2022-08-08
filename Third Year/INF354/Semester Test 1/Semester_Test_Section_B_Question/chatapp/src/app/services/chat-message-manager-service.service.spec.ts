import { TestBed } from '@angular/core/testing';

import { ChatMessageManagerServiceService } from './chat-message-manager-service.service';

describe('ChatMessageManagerServiceService', () => {
  let service: ChatMessageManagerServiceService;

  beforeEach(() => {
    TestBed.configureTestingModule({});
    service = TestBed.inject(ChatMessageManagerServiceService);
  });

  it('should be created', () => {
    expect(service).toBeTruthy();
  });
});
